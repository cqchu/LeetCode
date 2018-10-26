#ifndef __0031_H
#define __0031_H

/**********************************************************
Description:
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place and use only constant extra memory.
Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
**********************************************************/

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// 1, 7, 5, 9, 3 -> 1, 7, 9, 3, 5 若一直降序(9, 3), 则往前一直找到不降序的(5), 把后面降序中刚好比之大的(9)移到这个数字位置, 然后对后面的进行升序排序
    
// 1, 3 ,7, 5, 5

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int notDiscernIdx = nums.size()-2;
        while(notDiscernIdx>=0 && nums[notDiscernIdx]>=nums[notDiscernIdx+1])
            notDiscernIdx --;
 
        if(notDiscernIdx < 0) {
            sort(nums.begin(), nums.end());
            return ;
        }

        int nextNum = nums[notDiscernIdx+1], nextNumIdx = notDiscernIdx+1;
        for(int i=notDiscernIdx+2; i<nums.size(); i++) {
            if(nums[i]>nums[notDiscernIdx] && nums[i]<nextNum) {
                nextNum = nums[i];
                nextNumIdx = i;
            }
        }
        
        nums[nextNumIdx] = nums[notDiscernIdx];
        nums[notDiscernIdx] = nextNum;
        sort(nums.begin()+notDiscernIdx+1, nums.end());
    }
};


#endif

