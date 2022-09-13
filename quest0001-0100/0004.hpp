#ifndef __0004_H
#define __0004_H

/*********************************************************************
Description:
There are two sorted arrays nums1 and nums2 of size m and n respectively.
Find the median of the two sorted arrays. The overall run time complexity should
be O(log (m+n)). You may assume nums1 and nums2 cannot be both empty.

Example 1:
nums1 = [1, 3]
nums2 = [2]
The median is 2.0

Example 2:
nums1 = [1, 2]
nums2 = [3, 4]
The median is (2 + 3)/2 = 2.5
********************************************************************/

#include "../includes.hpp"

class Solution {
  public:
    /****************************************************************
    // complexity is O(m+n)
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        double median = 0;
        int idx1 = 0, idx2 = 0;
        for(int i=0; i<(nums1.size()+nums2.size()-1)/2; i++)
        {
            if(idx1 < nums1.size() && (idx2 >= nums2.size() || nums1[idx1]
    <= nums2[idx2]))
                ++idx1;
            else if(idx2 < nums2.size() && (idx1 >= nums1.size() ||
    nums1[idx1] > nums2[idx2]))
                ++idx2;
        }

        if(idx1 < nums1.size() && (idx2 >= nums2.size() || nums1[idx1] <=
    nums2[idx2])) median = nums1[idx1++]; else if(idx2 < nums2.size() &&
    (idx1 >= nums1.size() || nums1[idx1] > nums2[idx2])) median =
    nums2[idx2++];

        if((nums1.size()+nums2.size())%2 == 0)
        {
            if(idx1 < nums1.size() && (idx2 >= nums2.size() || nums1[idx1]
    <= nums2[idx2])) median += nums1[idx1++]; else if(idx2 < nums2.size() &&
    (idx1 >= nums1.size() || nums1[idx1] > nums2[idx2])) median +=
    nums2[idx2++]; median = median / 2.0;
        }
        return median;
    }
    *****************************************************************/

    // 要想复杂度降低为O(log(m+n)),
    // 逐元素合并数组然后查找最中间元素显然不行, 此时需要更有效的做法
    // 现在考虑是否可以在此已排序的数组中二分查找目标元素,
    // 但是同时在两个数组中二分查找显然也是不可行的
    // leetcode给的solution时先确定nums1和nums2中目标元素下标间恒等关系,
    // 然后在一个nums中二分查找 此恒等关系即(idx1 + idx2) * 2 = nums1.size +
    // nums2.size(不考虑特殊的边界情况) 且 min(big part) >= max(small part),
    // big part即idx1右边和idx2右边组成的部分, small part则相反
    // 即nums2[idx2+1] > nums1[idx1] && nums1[idx1+1] > nums2[idx2]
    // 而作者考虑问题时把大于median的数看做一个整体,
    // 小于median的看做一个整体 而非把两个数组分别看为一个整体

    // consider b = 1, 3, 5, 7, 9; a = 2, 4, 6, 8, 10
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        vector<int> &A =
            nums1.size() > nums2.size() ? nums2 : nums1; // the short one
        vector<int> &B =
            nums1.size() <= nums2.size() ? nums2 : nums1; // the long one
        int totalLen = nums1.size() + nums2.size();
        int m = A.size(), n = B.size();

        int iMin = 0, iMax = m, halfLen = (totalLen + 1) / 2;
        while (iMin <= iMax) {
            int i = (iMin + iMax) / 2;
            int j = halfLen - i;
            if (i < iMax && B[j - 1] > A[i]) {
                iMin = i + 1; // i is too small
            } else if (i > iMin && A[i - 1] > B[j]) {
                iMax = i - 1; // i is too big
            } else {          // i is perfect
                int maxLeft = 0;
                if (i == 0)
                    maxLeft = B[j - 1];
                else if (j == 0)
                    maxLeft = A[i - 1];
                else
                    maxLeft = A[i - 1] > B[j - 1] ? A[i - 1] : B[j - 1];
                if ((m + n) % 2 == 1)
                    return maxLeft;

                int minRight = 0;
                if (i == m)
                    minRight = B[j];
                else if (j == n)
                    minRight = A[i];
                else
                    minRight = B[j] < A[i] ? B[j] : A[i];

                return (maxLeft + minRight) / 2.0;
            }
        }
        return 0.0;
    }
};

#endif