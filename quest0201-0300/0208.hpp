#ifndef __0208_H
#define __0208_H

/*****************************************************
Description:
A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently
store and retrieve keys in a dataset of strings. There are various applications of this
data structure, such as autocomplete and spellchecker.

Implement the Trie class:
Trie() Initializes the trie object.
void insert(String word) Inserts the string word into the trie.
boolean search(String word) Returns true if the string word is in the trie (i.e., was
inserted before), and false otherwise. boolean startsWith(String prefix) Returns true if
there is a previously inserted string word that has the prefix prefix, and false
otherwise.

Example 1:
Input
["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
[[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
Output
[null, null, true, false, true, null, true]
Explanation
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // return True
trie.search("app");     // return False
trie.startsWith("app"); // return True
trie.insert("app");
trie.search("app");     // return True

Constraints:
1 <= word.length, prefix.length <= 2000
word and prefix consist only of lowercase English letters.
At most 3 * 10^4 calls in total will be made to insert, search, and startsWith
*****************************************************/

#include "../includes.hpp"

class Trie {
    struct TreeNode {
        TreeNode() {
            for (auto &child : childs) {
                child = nullptr;
            }
            is_endpoint = false;
        }
        std::array<TreeNode *, 26> childs;
        bool is_endpoint;

        TreeNode *find_or_add_child(char c) {
            size_t idx = c - 'a';
            if (childs[idx] == nullptr) {
                childs[idx] = new TreeNode();
            }
            return childs[idx];
        }

        TreeNode *find(char c) { return childs[c - 'a']; }

        ~TreeNode() {
            for (auto &child : childs) {
                if (child) {
                    delete child;
                }
            }
        }
    };
    TreeNode *root;

public:
    Trie() { root = new TreeNode(); }

    ~Trie() { delete root; }

    void insert(string word) {
        TreeNode *cur = root;
        for (auto &&ch : word) {
            cur = cur->find_or_add_child(ch);
        }
        cur->is_endpoint = true;
    }

    bool search(string word) {
        TreeNode *cur = root;
        for (auto &&ch : word) {
            if (cur == nullptr)
                return false;
            cur = cur->find(ch);
        }
        if (cur == nullptr) {
            return false;
        }
        return cur->is_endpoint;
    }

    bool startsWith(string prefix) {
        TreeNode *cur = root;
        for (auto &&ch : prefix) {
            if (cur == nullptr)
                return false;
            cur = cur->find(ch);
        }
        if (cur == nullptr) {
            return false;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

#endif
