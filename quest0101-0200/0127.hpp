#ifndef __0127_H
#define __0127_H

/****************************************************
Description:
Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:
1. Only one letter can be changed at a time.
2. Each transformed word must exist in the word list.

Note:
1. Return 0 if there is no such transformation sequence.
2. All words have the same length.
3. All words contain only lowercase alphabetic characters.
4. You may assume no duplicates in the word list.
5. You may assume beginWord and endWord are non-empty and are not the same.

Example 1:
Input:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

Output: 5
Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Example 2:
Input:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

Output: 0
Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.
****************************************************/

#include "../includes.hpp"

class Solution {
public:
    /* Construct a graph, the vertexes are the words, two vertexes are connected if they have only a different letter. Then the shortest path between the beginWord and the endWord is the answer
    
    Input:
        beginWord = "hit",
        endWord = "cog",
        wordList = ["hot","dot","dog","lot","log","cog"]
        
    Graph:
        hit - hot - lot -  log
                \   /     /   \
                 dot - dog  - cog
        We can find the shortest path between hit and cog easily

    Because the weight of all edges are the same, so we can solve it by bfs
    */
    bool isConnected(string s, string t) {
        if (s.size() != t.size())
            return false;
        int cnt = 0;
        for (int i=0; i<s.size(); i++)
            if (s[i] != t[i]) {
                cnt ++;
                if (cnt > 1)
                    return false;
            }
        return true;
    }
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (beginWord.size() != endWord.size())
            return 0;
        
        wordList.push_back(beginWord);
        vector<bool> visit(wordList.size(), false);
        visit[visit.size()-1] = true;
        queue<int> q;
        q.push(wordList.size()-1);
        q.push(-1);
        int depth = 2;
        
        while(!q.empty()) {
            int idx = q.front();
            q.pop();
            
            if (idx == -1) {
                if (q.empty())
                    break;
                q.push(-1);
                depth ++;
                continue;
            }
            
            for (int i=0; i<wordList.size(); i++) {
                if (visit[i] == false && isConnected(wordList[idx], wordList[i])) {
                    if (wordList[i] == endWord)
                        return depth;
                    q.push(i);
                    visit[i] = true;
                }
                    
            }
        }
        return 0;
    }
};

#endif
