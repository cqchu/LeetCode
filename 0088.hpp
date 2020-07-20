#ifndef __0088_H
#define __0088_H

/**********************************************
Description:
Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:
    The number of elements initialized in nums1 and nums2 are m and n respectively.
    You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2.

Example:
Input:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3
Output: [1,2,2,3,5,6]
**********************************************/

#include "includes.hpp"

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int nums1Idx = m-1, nums2Idx = n - 1, newIdx = m+n-1;
        while(newIdx >= 0 && nums1Idx >= 0 && nums2Idx >= 0) {
            if (nums1[nums1Idx] > nums2[nums2Idx]) {
                nums1[newIdx--] = nums1[nums1Idx--];
            }
            else {
                nums1[newIdx--] = nums2[nums2Idx--];
            }
        }
        while(nums2Idx >= 0) {
            nums1[newIdx--] = nums2[nums2Idx--];
        }
    }
};

#endif