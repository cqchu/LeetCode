#ifndef __0071_H
#define __0071_H

/****************************************************
Description:
Given an absolute path for a file (Unix-style), simplify it. Or in other words,
convert it to the canonical path. In a UNIX-style file system, a period .
refers to the current directory. Furthermore, a double period .. moves the
directory up a level. For more information, see: Absolute path vs relative path
in Linux/Unix Note that the returned canonical path must always begin with a
slash /, and there must be only a single slash / between two directory names.
The last directory name (if it exists) must not end with a trailing /. Also,
the canonical path must be the shortest string representing the absolute path.

Example 1:
Input: "/home/"
Output: "/home"
Explanation: Note that there is no trailing slash after the last directory
name.

Example 2:
Input: "/../"
Output: "/"
Explanation: Going one level up from the root directory is a no-op, as the root
level is the highest level you can go.

Example 3:
Input: "/home//foo/"
Output: "/home/foo"
Explanation: In the canonical path, multiple consecutive slashes are replaced
by a single one.

Example 4:
Input: "/a/./b/../../c/"
Output: "/c"

Example 5:
Input: "/a/../../b/../c//.//"
Output: "/c"

Example 6:
Input: "/a//b////c/d//././/.."
Output: "/a/b/c"
****************************************************/

#include "../includes.hpp"

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> dir;
        path = path + "/";
        int curPos = 0;
        string tmpdir = "";
        for (int i = 0; i < path.size(); i++) {
            if (path[i] == '.') {
                tmpdir = tmpdir + path[i];
            } else if (path[i] == '/') {
                if (tmpdir == "..") {
                    if (!dir.empty()) {
                        dir.pop();
                    }
                } else if (tmpdir == ".") {
                    ;
                } else if (tmpdir != "") {
                    dir.push(tmpdir);
                }
                tmpdir = "";
            } else {
                tmpdir = tmpdir + path[i];
            }
        }
        string res = "";
        while (!dir.empty()) {
            res = "/" + dir.top() + res;
            dir.pop();
        }
        if (res == "")
            res = "/";
        return res;
    }
};

#endif