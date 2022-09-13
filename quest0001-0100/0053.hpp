#ifndef __0053_H
#define __0053_H

/*************************************************
Description:
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

Example:
Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.

Follow up:
If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
*************************************************/

#include "includes.hpp"

// class Solution {
// public:
//     int maxSubArray(vector<int>& nums) {
//         int lIdx=0, rIdx=0, value=0;
//         div(0, nums.size(), nums, lIdx, rIdx, value);
//         return value;
//     }
    
//     // divide and conquer
//     void div(int startPos, int endPos, vector<int>& nums, int& lIdx, int& rIdx, int& value) {
//         if (endPos <= startPos)
//             return;
//         if (endPos - startPos == 1) {
//             lIdx = startPos;
//             rIdx = endPos;
//             value = nums[startPos];
//             return;
//         }
//         int midPos = (startPos + endPos) / 2;
//         int crossLIdx, crossRIdx, crossValue;
//         int leftLIdx, leftRIdx, leftValue;
//         int rightLIdx, righeRIdx, rightValue;
        
//         div(startPos, midPos, nums, leftLIdx, leftRIdx, leftValue);
//         div(midPos, endPos, nums, rightLIdx, righeRIdx, rightValue);
//         findMaxCrossSubarray(startPos, endPos, nums, crossLIdx, crossRIdx, crossValue);
        
//         if (crossValue >= leftValue && crossValue >= rightValue) {
//             lIdx = crossLIdx;
//             rIdx = crossRIdx;
//             value = crossValue;
//         }
//         else if (leftValue >= crossValue && leftValue >= rightValue) {
//             lIdx = leftLIdx;
//             rIdx = leftRIdx;
//             value = leftValue;
//         }
//         else if (rightValue >= crossValue && rightValue >= leftValue) {
//             lIdx = rightLIdx;
//             rIdx = righeRIdx;
//             value = rightValue;
//         }
//     }
    
//     void findMaxCrossSubarray(int startPos, int endPos, vector<int>& nums, int& lIdx, int& rIdx, int& value) {
//         int midPos = (startPos + endPos) / 2;
//         lIdx = rIdx = midPos;
//         int tsum=0, maxsuml=INT_MIN, maxsumr=INT_MIN;
        
//         for (int i=midPos-1; i>=startPos; i--) {
//             tsum = tsum + nums[i];
//             if (tsum > maxsuml) {
//                 maxsuml = tsum;
//                 lIdx = i;
//             }
//         }
//         tsum = 0;
//         for (int i=midPos; i<endPos; i++) {
//             tsum = tsum + nums[i];
//             if (tsum > maxsumr) {
//                 maxsumr = tsum;
//                 rIdx = i+1;
//             }
//         }
//         value = maxsuml + maxsumr;
//     }
// };

class Solution {
public:
    int maxSubArray(vector<int>& nums) {     
        // OPT[i] = max(OPT[i-1] + i, OPT[i-1])
        int actualMax = nums[0], maxSoFar = nums[0];
        // cout << actualMax << " ";
        for (int i = 1; i < nums.size(); i++)
        {
            maxSoFar = maxSoFar > 0 ? maxSoFar + nums[i] : nums[i]; // maxSoFar > 0, ˵��ǰ������Ӵ�����gain��, �ʶ�ֵ�ñ���    
            actualMax = max(actualMax, maxSoFar);                   // maxSoFar����һ��DP��״̬, 
            // cout << actualMax << " ";
        }
        return actualMax;
    }
};

#endif
