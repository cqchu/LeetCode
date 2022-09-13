#ifndef __0042_H
#define __0042_H

/*******************************************************
Description:
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!

Example:
Input: [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
********************************************************/

#include "includes.hpp"

class Solution {
public:
    int compute(const vector<int>& height, const int left, const int right) {
        int highest = height[left] > height[right] ? height[right] : height[left];
        int acc = 0;
        for (int i=left+1; i<right; i++) {
            if (highest > height[i])
                acc = acc + highest - height[i];
        }
        return acc;
    }
    int trap(const vector<int>& height) {
        if (height.size() < 3) {
            return 0;
        }
        multimap<int, int, greater<int> > localMax;     // pair<height, index>
        if (height[0] >= height[1]) {
            localMax.insert(pair<int, int>{height[0], 0});
        }
        if (height[height.size()-1] >= height[height.size()-2]) {
            localMax.insert(pair<int, int>{height[height.size()-1], height.size()-1});
        }
        for(int i=1; i<height.size()-1; i++) {
            if (height[i] >= height[i-1] && height[i] >= height[i+1]) {
                localMax.insert(pair<int, int>{height[i], i});
            }
        }
        
        if (localMax.size() < 2) {
            return 0;
        }
        
        int totalWater = 0;
        // compute left part
        multimap<int, int>::iterator it=localMax.begin();
        int highest = it->second;
        it++;
        while (it != localMax.end()) {
            if (it->second <= highest) {
                totalWater = totalWater + compute(height, it->second, highest);
                highest = it->second;
            }
            it ++;
        }
        
        it=localMax.begin();
        highest = it->second;
        it++;
        while (it != localMax.end()) {
            if (it->second >= highest) {
                totalWater = totalWater + compute(height, highest, it->second);
                highest = it->second;
            }
            it ++;
        }
        return totalWater;
    }
};

#endif
