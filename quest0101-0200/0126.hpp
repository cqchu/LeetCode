#ifndef __0126_H
#define __0126_H

/****************************************************
Description:
Given two words (beginWord and endWord), and a dictionary's word list, find all
shortest transformation sequence(s) from beginWord to endWord, such that:
1. Only one letter can be changed at a time
2. Each transformed word must exist in the word list. Note that beginWord is
not a transformed word.

Note:
1. Return an empty list if there is no such transformation sequence.
2. All words have the same length.
3. All words contain only lowercase alphabetic characters.
4. You may assume no duplicates in the word list.
5. You may assume beginWord and endWord are non-empty and are not the same.

Example 1:
Input:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

Output:
[
  ["hit","hot","dot","dog","cog"],
  ["hit","hot","lot","log","cog"]
]

Example 2:
Input:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

Output: []
Explanation: The endWord "cog" is not in wordList, therefore no possible
transformation.
****************************************************/

#include "../includes.hpp"

/* Construct a graph, the vertexes are the words, two vertexes are connected if
   they have only a different letter. Then the shortest path between the
   beginWord and the endWord is the answer

    Input:
        beginWord = "hit",
        endWord = "cog",
        wordList = ["hot","dot","dog","lot","log","cog"]

    Graph:
        hit - hot - lot -  log
                \   /     /   \
                 dot - dog  - cog
        We can find the shortest path between hit and cog easily

    Because the weight of all edges are the same, so we can solve it by
   birection bfs
*/

class Solution {
public:
    void construct(unordered_multimap<string, string> &path,
                   vector<vector<string>> &res, string &curWord) {
        if (path.count(curWord) == 0) {
            res.push_back(vector<string>());
            return;
        }
        auto iter = path.equal_range(curWord);
        for (auto it = iter.first; it != iter.second; ++it) {
            // cout << it->first << " " << it->second << endl;
            vector<vector<string>> curPath;
            construct(path, curPath, it->second);
            for (int i = 0; i < curPath.size(); i++) {
                curPath[i].push_back(it->second);
                res.push_back(curPath[i]);
            }
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord,
                                       vector<string> &wordList) {
        vector<vector<string>> res;
        if (beginWord.size() != endWord.size())
            return res;
        unordered_set<string> unvisited(wordList.begin(), wordList.end());
        if (unvisited.find(endWord) == unvisited.end())
            return res;
        unvisited.erase(endWord);
        unvisited.erase(beginWord);
        unordered_set<string> beginSet = {beginWord}, endSet = {endWord},
                              intersect;
        unordered_multimap<string, string> beginPath, endPath;

        while (!beginSet.empty() && !endSet.empty()) {
            if (!intersect.empty())
                break;

            unordered_set<string> &curSet =
                beginSet.size() < endSet.size() ? beginSet : endSet;
            unordered_set<string> &oppoSet =
                beginSet.size() < endSet.size() ? endSet : beginSet;
            unordered_multimap<string, string> &curPath =
                beginSet.size() < endSet.size() ? beginPath : endPath;
            unordered_set<string> nextLevel;
            // cout << "one time" << endl;
            // for (auto s: curSet)
            //     cout << s << " ";
            // cout << endl;

            vector<string> toBeErase;

            for (string curWord : curSet) {
                for (int i = 0; i < curWord.size(); i++) {
                    for (char c = 'a'; c <= 'z'; c++) {
                        string target = curWord;
                        target[i] = c;
                        if (oppoSet.count(target) != 0) {
                            intersect.insert(target);
                            curPath.insert(make_pair(target, curWord));
                        }
                        if (unvisited.count(target) != 0) {
                            nextLevel.insert(target);
                            curPath.insert(make_pair(target, curWord));
                            toBeErase.push_back(target);
                        }
                    }
                }
            }
            for (auto ele : toBeErase)
                unvisited.erase(ele);
            swap(nextLevel, curSet);
            // for (auto s: curSet)
            //     cout << s << " ";
            // cout << endl;
        }

        for (string intersectWord : intersect) {
            // cout << intersectWord << endl;
            vector<vector<string>> prefix, postfix;
            construct(beginPath, prefix, intersectWord);
            construct(endPath, postfix, intersectWord);
            // for (auto a: postfix) {
            //     for (auto b: a)
            //         cout << b << " ";
            //     cout << endl;
            // }
            for (int i = 0; i < prefix.size(); i++) {
                prefix[i].push_back(intersectWord);
                for (int j = 0; j < postfix.size(); j++) {
                    vector<string> tmp = prefix[i];
                    tmp.insert(tmp.end(), postfix[j].rbegin(),
                               postfix[j].rend());
                    res.push_back(tmp);
                }
            }
        }
        return res;
    }
};

#endif
