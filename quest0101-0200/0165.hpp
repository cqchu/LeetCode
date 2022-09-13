#ifndef __0165_H
#define __0165_H

/*****************************************************
Description:
Given two version numbers, version1 and version2, compare them.
Version numbers consist of one or more revisions joined by a dot '.'. Each
revision consists of digits and may contain leading zeros. Every revision
contains at least one character. Revisions are 0-indexed from left to right,
with the leftmost revision being revision 0, the next revision being revision 1,
and so on. For example 2.5.33 and 0.1 are valid version numbers. To compare
version numbers, compare their revisions in left-to-right order. Revisions are
compared using their integer value ignoring any leading zeros. This means that
revisions 1 and 001 are considered equal. If a version number does not specify a
revision at an index, then treat the revision as 0. For example, version 1.0 is
less than version 1.1 because their revision 0s are the same, but their revision
1s are 0 and 1 respectively, and 0 < 1.

Return the following:
* If version1 < version2, return -1.
* If version1 > version2, return 1.
* Otherwise, return 0.


Example 1:
Input: version1 = "1.01", version2 = "1.001"
Output: 0
Explanation: Ignoring leading zeroes, both "01" and "001" represent the same
integer "1".

Example 2:
Input: version1 = "1.0", version2 = "1.0.0"
Output: 0
Explanation: version1 does not specify revision 2, which means it is treated as
"0".

Example 3:
Input: version1 = "0.1", version2 = "1.1"
Output: -1
Explanation: version1's revision 0 is "0", while version2's revision 0 is "1". 0
< 1, so version1 < version2.
*****************************************************/

#include "../includes.hpp"

class Solution {
  public:
    int convert(string revision) {
        int irevision = 0;
        for (int i = 0; i < revision.size(); i++) {
            irevision = irevision * 10 + revision[i] - '0';
        }
        return irevision;
    }

    int compareVersion(string version1, string version2) {
        int pos1 = 0, pos2 = 0;
        while (pos1 < version1.size() || pos2 < version2.size()) {
            int nextDot1 = pos1, nextDot2 = pos2;
            while (nextDot1 < version1.size() && version1[nextDot1] != '.')
                nextDot1++;
            while (nextDot2 < version2.size() && version2[nextDot2] != '.')
                nextDot2++;

            string srevision1 = version1.substr(pos1, nextDot1 - pos1);
            string srevision2 = version2.substr(pos2, nextDot2 - pos2);
            // cout << pos1 << " " << nextDot1 << "; " << pos2 << " " <<
            // nextDot2 << endl;
            pos1 =
                nextDot1 + 1 > version1.size() ? version1.size() : nextDot1 + 1;
            pos2 =
                nextDot2 + 1 > version2.size() ? version2.size() : nextDot2 + 1;

            int irevision1 = convert(srevision1),
                irevision2 = convert(srevision2);
            if (irevision1 == irevision2)
                continue;
            else if (irevision1 < irevision2)
                return -1;
            else
                return 1;
        }
        return 0;
    }
};

#endif
