import argparse
import os
import re
import subprocess
import tempfile
from functools import partial
from multiprocessing import Manager

from tqdm.contrib.concurrent import process_map

failed_files = Manager().list()

def process_file(file, clang_format, write):
    original_source = open(file, "r").read()
    source = original_source
    result = subprocess.check_output(
        [
            clang_format,
            "-style={BasedOnStyle: LLVM, IndentWidth: 4, AccessModifierOffset: -4, ColumnLimit: 88}",
            "-verbose",
            "-assume-filename={}".format(file),
            # file,
        ],
        input=bytes(source.encode("utf-8")),
    )

    result = result.decode("utf-8")

    if write and original_source != result:
        with tempfile.NamedTemporaryFile(
            dir=os.path.dirname(file), delete=False
        ) as tmp_file:
            tmp_file.write(result.encode("utf-8"))
        os.rename(tmp_file.name, file)
    else:
        ret_code = subprocess.run(
            ["diff", "--color=always", file, "-"], input=bytes(result.encode("utf-8")),
        ).returncode

        # man diff: 0 for same, 1 for different, 2 if trouble.
        if ret_code == 2:
            raise RuntimeError("format process (without overwrite) failed")
        if ret_code != 0:
            print(file)
            global failed_files
            failed_files.append(file)

def main():
    parser = argparse.ArgumentParser(
        description="format source files using clang-format",
        formatter_class=argparse.ArgumentDefaultsHelpFormatter,
    )

    parser.add_argument(
        "-p", "--path", nargs="+", help="file name or path", default=None
    )
    parser.add_argument(
        "-w",
        "--write",
        action="store_true",
        help="use formatted file to replace original file.",
        default=True
    )
    parser.add_argument(
        "--clang-format",
        default=os.getenv("CLANG_FORMAT", "clang-format-12"),
        help="clang-format executable name; it can also be "
        "modified via the CLANG_FORMAT environment var",
    )
    args = parser.parse_args()

    format_type = [".cpp", ".c", ".h", ".cu", ".cuh", ".inl", ".hpp"]

    def getfiles(path):
        rst = []
        for p in os.listdir(path):
            p = os.path.join(path, p)
            if os.path.isdir(p):
                rst += getfiles(p)
            elif (
                os.path.isfile(p)
                and not os.path.islink(p)
                and os.path.splitext(p)[1] in format_type
            ):
                rst.append(p)
        return rst

    if args.path is None:
        root_dir = os.path.dirname(os.path.abspath(__file__))
        args.path = []
        for xx in os.listdir(root_dir):
            if (xx.startswith("quest") and xx.endswith("00")) or xx.endswith(".hpp"):
                args.path.append(os.path.join(root_dir, xx))

    files = []

    for path in args.path:
        if os.path.isdir(path):
            files += getfiles(path)
        elif os.path.isfile(path):
            files.append(path)
        else:
            raise ValueError("Invalid path {}".format(path))

    version = subprocess.check_output([args.clang_format, "--version",],)
    version = version.decode("utf-8")

    process_map(
        partial(process_file, clang_format=args.clang_format, write=args.write,),
        files,
        chunksize=10,
    )

    if failed_files:
        raise RuntimeError("above files are not properly formatted!")


if __name__ == "__main__":
    main()
