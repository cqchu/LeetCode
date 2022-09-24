#ifndef __0088_H
#define __0088_H

/**********************************************
Description:
The gray code is a binary numeral system where two successive values differ in
only one bit. Given a non-negative integer n representing the total number of
bits in the code, print the sequence of gray code. A gray code sequence must
begin with 0.

Example 1:
Input: 2
Output: [0,1,3,2]
Explanation:
00 - 0
01 - 1
11 - 3
10 - 2

For a given n, a gray code sequence may not be uniquely defined.
For example, [0,2,3,1] is also a valid gray code sequence.
00 - 0
10 - 2
11 - 3
01 - 1

Example 2:
Input: 0
Output: [0]
Explanation: We define the gray code sequence to begin with 0.
             A gray code sequence of n has size = 2n, which for n = 0 the size
is 20 = 1. Therefore, for n = 0 the gray code sequence is [0].
**********************************************/

#include "../includes.hpp"

class Solution {
public:
    /**
     * In Gray code, the key is symmetry, for example, n = 3
     0 0 0    // The top part is factually the Gray code with n = 2
     0 0 1
     0 1 1
     0 1 0
     -----
     1 1 0    // The bottom part is symmetry with the top part but the `1`
     int bit 3 1 1 1 1 0 1 1 0 0
     */
    void recurse(vector<int> &res, int n) {
        if (n == 0) {
            res.push_back(0);
            return;
        }

        recurse(res, n - 1);
        int resLen = res.size();
        for (int i = 0; i < resLen; i++) {
            res.push_back(resLen + res[resLen - i - 1]);
        }
    }

    vector<int> grayCode(int n) {
        vector<int> res;
        recurse(res, n);
        return res;
    }
};

#endif