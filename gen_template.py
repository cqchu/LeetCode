import argparse
import warnings
import os

parser = argparse.ArgumentParser(description = 'LeetCode Template Generator')
parser.add_argument('-i', '--quest-ids', type=int, nargs='+', default=-1)

def get_dir(quest_id):
    xx = (quest_id - 1) // 100
    yy = xx + 1
    assert xx < 100 and yy < 100, 'quest id should < 9901'
    dir_name = f'quest{xx:0>2d}01-{yy:0>2d}00'
    root_dir = os.path.dirname(os.path.abspath(__file__))
    return os.path.join(root_dir, dir_name)

if __name__ == '__main__':
    args = parser.parse_args()
    quest_ids = args.quest_ids

    for quest_id in quest_ids:
        if not isinstance(quest_id, int) or quest_id < 1:
            warnings.warn(f'quest id {quest_id} is in valid, nothing happened')
            exit()

    for quest_id in quest_ids:
        dir_name = get_dir(quest_id)
        file_name = f'{quest_id:0>4d}.hpp'
        file_path = os.path.join(dir_name, file_name)
        assert not os.path.exists(file_path), f'{file_path} for quest {quest_id} exists'

        with open(file_path, 'w') as f:
            f.write(f'#ifndef __{quest_id:0>4d}_H\n')
            f.write(f'#define __{quest_id:0>4d}_H\n\n')

            asterisk = 53 * '*'
            f.write(f'/{asterisk}\n')
            f.write('Description:\n\n')
            f.write(f'{asterisk}/\n\n')

            f.write('#include "../includes.hpp"\n\n')
            f.write('class Solution {\n')
            f.write('public:\n')
            f.write('    \n')
            f.write('};\n\n')

            f.write('#endif\n')
        