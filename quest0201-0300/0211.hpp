#ifndef __0211_H
#define __0211_H

/*****************************************************
Description:
Design a data structure that supports adding new words and finding if a string matches
any previously added string.

Implement the WordDictionary class:

* WordDictionary() Initializes the object.
* void addWord(word) Adds word to the data structure, it can be matched later.
* bool search(word) Returns true if there is any string in the data structure that
matches word or false otherwise. word may contain dots '.' where dots can be matched
with any letter.

Example:
Input
["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
Output
[null,null,null,null,false,true,true,true]
Explanation
WordDictionary wordDictionary = new WordDictionary();
wordDictionary.addWord("bad");
wordDictionary.addWord("dad");
wordDictionary.addWord("mad");
wordDictionary.search("pad"); // return False
wordDictionary.search("bad"); // return True
wordDictionary.search(".ad"); // return True
wordDictionary.search("b.."); // return True

Constraints:
* 1 <= word.length <= 25
* word in addWord consists of lowercase English letters.
* word in search consist of '.' or lowercase English letters.
* There will be at most 3 dots in word for search queries.
* At most 104 calls will be made to addWord and search.
*****************************************************/

#include "../includes.hpp"

class WordDictionary {
    struct TreeNode {
        std::array<TreeNode *, 27> subs = {nullptr};
        TreeNode() = default;
    };
    struct CharTree {
        TreeNode *head;
        CharTree() { head = new TreeNode(); }
        void add_str(const std::string &str) {
            if (str.size() == 0) {
                return;
            }
            TreeNode *cur = head;
            for (auto ch : str) {
                size_t idx = ch - 'a';
                if (cur->subs[idx] == nullptr) {
                    cur->subs[idx] = new TreeNode();
                }
                cur = cur->subs[idx];
            }
            cur->subs[26] = new TreeNode();
        }

        bool recursive(const std::string &str, size_t idx, TreeNode *node) {
            if (node == nullptr) {
                return false;
            }
            if (idx >= str.size()) {
                if (node->subs[26] != nullptr) {
                    return true;
                } else {
                    return false;
                }
            }
            auto ch = str[idx];
            if (ch == '.') {
                for (TreeNode *sub : node->subs) {
                    if (recursive(str, idx + 1, sub)) {
                        return true;
                    }
                }
                return false;
            } else {
                return recursive(str, idx + 1, node->subs[ch - 'a']);
            }
        }

        bool find_str(const std::string &str) {
            if (str.size() == 0) {
                return true;
            }
            return recursive(str, 0, head);
        }
    };

public:
    CharTree ct;
    WordDictionary() {}

    void addWord(string word) { ct.add_str(word); }

    bool search(string word) { return ct.find_str(word); }
};

#endif
