#ifndef __0060_H
#define __0060_H

/***************************************************
Description:
The set [1,2,3,...,n] contains a total of n! unique permutations.
By listing and labeling all of the permutations in order, we get the following
sequence for n = 3: "123" "132" "213" "231" "312" "321" Given n and k, return
the kth permutation sequence.

Note:
    Given n will be between 1 and 9 inclusive.
    Given k will be between 1 and n! inclusive.

Example 1:
Input: n = 3, k = 3
Output: "213"

Example 2:
Input: n = 4, k = 9
Output: "2314"
***************************************************/

#include "../includes.hpp"

class Solution {
public:
    int factorial(vector<int> &fac, int i) {
        if (i == 1) {
            fac[i - 1] = 1;
        } else {
            fac[i - 1] = i * factorial(fac, i - 1);
        }
        return fac[i - 1];
    }
    int findI(vector<bool> &flag, int i) {
        int cnt = 0;
        for (int j = 0; j < flag.size(); j++) {
            if (flag[j] == false)
                cnt++;
            if (i == cnt) {
                flag[j] = true;
                return j + 1;
            }
        }
        return 0;
    }
    string getPermutation(int n, int k) {
        vector<int> fac(n);
        factorial(fac, n);

        string res(n, 'a');
        vector<bool> flag(n);
        for (int i = 0; i < n - 1; i++) {
            int tcnt = ceil(k * 1.0 / fac[n - i - 2]);
            res[i] = findI(flag, tcnt) + '0';
            k = k % fac[n - i - 2];
            if (k == 0)
                k = fac[n - i - 2];
        }
        res[n - 1] = findI(flag, 1) + '0';
        return res;
    }
};

#endif