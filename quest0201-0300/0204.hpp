#ifndef __0204_H
#define __0204_H

/*****************************************************
Description:
Given an integer n, return the number of prime numbers that are strictly less than n.

Example 1:
Input: n = 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.

Example 2:
Input: n = 0
Output: 0

Example 3:
Input: n = 1
Output: 0

Constraints:
0 <= n <= 5 * 10^6
*****************************************************/

#include "../includes.hpp"

class Solution {
public:
    int countPrimes(int n) {
        if (n < 2)
            return 0;
        std::vector<bool> is_prime(n, true);

        auto update = [&](long prime) -> void {
            for (long idx = prime * prime; idx < n; idx += prime) {
                is_prime[idx] = false;
            }
        };

        for (int i = 2; i * i < n; ++i) {
            if (is_prime[i] == true) {
                update(i);
            }
        }

        int cnt = 0;
        for (int i = 2; i < n; ++i) {
            if (is_prime[i]) {
                cnt += 1;
            }
        }

        return cnt;
    }
};

#endif
