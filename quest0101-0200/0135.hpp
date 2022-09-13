#ifndef __0135_H
#define __0135_H

/****************************************************
Description:
There are N children standing in a line. Each child is assigned a rating value.
You are giving candies to these children subjected to the following requirements:
Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?

Example 1:
Input: [1,0,2]
Output: 5
Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.

Example 2:
Input: [1,2,2]
Output: 4
Explanation: You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
             The third child gets 1 candy because it satisfies the above two conditions.
****************************************************/

#include "includes.hpp"

class Solution {
public:
    int candy(vector<int>& ratings) {
        // if (ratings.size() <= 1) {
        //     return ratings.size();
        // }
        // vector<int> left2right(ratings.size(), 1), right2left(ratings.size(), 1);
        // // from left to right
        // for (int i=0; i<ratings.size()-1; i++) {
        //     if (ratings[i+1] > ratings[i]) {
        //         left2right[i+1] = left2right[i] + 1;
        //     }
        // }

        // // from right to left
        // for (int i=ratings.size()-1; i>0; i--) {
        //     if (ratings[i-1] > ratings[i]) {
        //         right2left[i-1] = right2left[i] + 1;
        //     }
        // }

        // int total = 0;
        // for (int i=0; i<ratings.size(); i++) {
        //     total = total + max(left2right[i], right2left[i]);
        // }
        // return total;

        // we can using only a vector to replace the left2right and right2left, which will hurt the code readability
        if (ratings.size() <= 1) {
            return ratings.size();
        }
        vector<int> leftAndRight(ratings.size(), 1);
        // from left to right
        for (int i=0; i<ratings.size()-1; i++) {
            if (ratings[i+1] > ratings[i]) {
                leftAndRight[i+1] = leftAndRight[i] + 1;
            }
        }

        // from right to left
        for (int i=ratings.size()-1; i>0; i--) {
            if (ratings[i-1] > ratings[i]) {
                leftAndRight[i-1] = max(leftAndRight[i] + 1, leftAndRight[i-1]);
            }
        }
        int total = 0;
        for (int i=0; i<ratings.size(); i++) {
            total = total + leftAndRight[i];
        }
        return total;
    }
};

#endif
