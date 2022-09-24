#ifndef __0068_H
#define __0068_H

/********************************************
Description:
Given an array of words and a width maxWidth, format the text such that each
line has exactly maxWidth characters and is fully (left and right) justified.
You should pack your words in a greedy approach; that is, pack as many words as
you can in each line. Pad extra spaces ' ' when necessary so that each line has
exactly maxWidth characters. Extra spaces between words should be distributed
as evenly as possible. If the number of spaces on a line do not divide evenly
between words, the empty slots on the left will be assigned more spaces than
the slots on the right. For the last line of text, it should be left justified
and no extra space is inserted between words.

Note:
    A word is defined as a character sequence consisting of non-space
characters only. Each word's length is guaranteed to be greater than 0 and not
exceed maxWidth. The input array words contains at least one word.

Example 1:
Input:
words = ["This", "is", "an", "example", "of", "text", "justification."]
maxWidth = 16
Output:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]

Example 2:
Input:
words = ["What","must","be","acknowledgment","shall","be"]
maxWidth = 16
Output:
[
  "What   must   be",
  "acknowledgment  ",
  "shall be        "
]
Explanation: Note that the last line is "shall be    " instead of "shall be",
             because the last line must be left-justified instead of
fully-justified. Note that the second line is also left-justified becase it
contains only one word.

Example 3:
Input:
words =
["Science","is","what","we","understand","well","enough","to","explain",
         "to","a","computer.","Art","is","everything","else","we","do"]
maxWidth = 20
Output:
[
  "Science  is  what we",
  "understand      well",
  "enough to explain to",
  "a  computer.  Art is",
  "everything  else  we",
  "do                  "
]
********************************************/

#include "../includes.hpp"

class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int maxWidth) {
        vector<string> res;
        if (words.size() == 0)
            return res;
        int curLineLen = 0, startPos = 0, endPos = 0;
        for (int i = 0; i < words.size(); i++) {
            if (curLineLen + words[i].size() + max(0, (i - startPos)) >
                maxWidth) {
                int totalSpaceLen, avgSpaceLen, extraSpaceLen;
                totalSpaceLen = maxWidth - curLineLen;
                if (endPos - startPos - 1 != 0) {
                    avgSpaceLen = totalSpaceLen / (endPos - startPos - 1);
                    extraSpaceLen = totalSpaceLen % (endPos - startPos - 1);
                } else {
                    avgSpaceLen = totalSpaceLen;
                    extraSpaceLen = 0;
                }

                string avgSpace(avgSpaceLen, ' ');
                string tres = "";
                for (int j = startPos; j < endPos - 1; j++) {
                    tres = tres + words[j] + avgSpace;
                    if (extraSpaceLen-- > 0)
                        tres = tres + " ";
                }
                if (endPos - 1 != startPos)
                    tres = tres + words[endPos - 1];
                else
                    tres = tres + words[endPos - 1] + avgSpace;
                res.push_back(tres);

                startPos = i;
                endPos = i + 1;
                curLineLen = words[i].size();
            } else {
                endPos = i + 1;
                curLineLen = curLineLen + words[i].size();
            }
        }
        string tres = "";
        cout << startPos << endl;
        for (int j = startPos; j < words.size() - 1; j++) {
            tres = tres + words[j] + " ";
        }
        tres = tres + words[words.size() - 1];
        tres = tres + string(maxWidth - tres.size(), ' ');
        res.push_back(tres);

        return res;
    }
};

#endif
