#ifndef __0015_H
#define __0015_H

/**********************************************************
Description:
Given an array nums of n integers, are there elements a, b, c in nums such that
a + b + c = 0? Find all unique triplets in the array which gives the sum of
zero. Note: The solution set must not contain duplicate triplets.

Example:
Given array nums = [-1, 0, 1, 2, -1, -4],
A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
**********************************************************/

#include "../includes.hpp"

class Solution {
public:
    /*
    int cmp(vector<int> a, vector<int> b)
    {
        if(a[0] > b[0])
            return 1;
        if(a[0] == b[0])
        {
            if(a[1] > b[1])
                return 1;
            if(a[1] == b[1])
            {
                if(a[2] > b[2])
                    return 1;
                if(a[2] == b[2])
                    return 0;
            }
        }
        return -1;
    }

    vector<vector<int> > threeSum(vector<int>& nums) {
        vector<vector<int> > res;
        for(int i=0; i<nums.size(); i++)
            for(int j=i+1; j<nums.size(); j++)
                for(int k=j+1; k<nums.size(); k++)
                    if(nums[i] + nums[j] + nums[k] == 0)
                    {
                        vector<int> tmp;    // sort in ascending order
                        tmp.push_back(nums[i]);
                        tmp.push_back(nums[j]);
                        tmp.push_back(nums[k]);
                        sort(tmp.begin(), tmp.end());

                        int s = 0;
                        for(s=0; res.begin()+s!=res.end(); s++)
                        {
                            int a = cmp(tmp, res[s]);
                            if(a == 0)
                                break;
                            if(a > 0)
                            {
                                res.insert(res.begin()+s, tmp);
                                break;
                            }
                        }

                        if(res.begin()+s == res.end())
                            res.push_back(tmp);
                    }
        return res;
    }
    */

    // double pointor method
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> res;
        if (nums.size() == 0)
            return res;
        sort(nums.begin(), nums.end());
        int cur, startPtr, endPtr;

        for (cur = 0; nums[cur] <= 0 && cur < nums.size(); cur++) {
            if (cur > 0 && nums[cur - 1] == nums[cur])
                continue;

            startPtr = cur + 1;
            endPtr = nums.size() - 1;
            while (startPtr < endPtr) {
                if (nums[startPtr] + nums[endPtr] == -nums[cur]) {
                    vector<int> tmp;
                    tmp.push_back(nums[cur]);
                    tmp.push_back(nums[startPtr]);
                    tmp.push_back(nums[endPtr]);
                    res.push_back(tmp);
                    do {
                        startPtr++;
                    } while (nums[startPtr] == nums[startPtr - 1]);

                    do {
                        endPtr--;
                    } while (nums[endPtr] == nums[endPtr + 1]);
                } else if (nums[startPtr] + nums[endPtr] > -nums[cur]) {
                    do {
                        endPtr--;
                    } while (nums[endPtr] == nums[endPtr + 1]);
                } else {
                    do {
                        startPtr++;
                    } while (nums[startPtr] == nums[startPtr - 1]);
                }
            }
        }
        return res;
    }
};

#endif
