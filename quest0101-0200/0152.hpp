#ifndef __0152_H
#define __0152_H

/****************************************************
Description:
Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.

Example 1:
Input: [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.

Example 2:
Input: [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
****************************************************/

#include "../includes.hpp"

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        vector<int> positiveDp(nums.size(), 0);
        vector<int> negativeDp(nums.size(), 0);
        positiveDp[0] = nums[0] >= 0 ? nums[0] : 0;
        negativeDp[0] = nums[0] < 0 ? nums[0] : 0;
        int maxVal = nums[0];
        for (int i=1; i<nums.size(); i++) {
            if (nums[i] == 0) {
                positiveDp[i] = 0;
                negativeDp[i] = 0;
            }
            else if (nums[i] > 0) {
                positiveDp[i] = max(positiveDp[i-1] * nums[i], nums[i]);
                negativeDp[i] = negativeDp[i-1] * nums[i];
            }
            else {
                positiveDp[i] = negativeDp[i-1] * nums[i];
                negativeDp[i] = min(positiveDp[i-1] * nums[i], nums[i]);
            }
            maxVal = max(maxVal, positiveDp[i]);
        }
        // for (int i=0; i<nums.size(); i++) {
        //     cout << positiveDp[i] << ' ';
        // }
        // cout << endl;
        // for (int i=0; i<nums.size(); i++) {
        //     cout << negativeDp[i] << ' ';
        // }
        cout << endl;
        return maxVal;
    }
};

#endif