#ifndef __INCLUDES_H
#define __INCLUDES_H

#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define IO std::cout
#define IO_WITH_INFO IO << __FILE__ << ":" << __LINE__ << " -> "
#define EOL std::endl
#define HOLDER(x) (x)

template <typename T> void print_impl(T &&inp) { IO << inp << " "; }

template <typename T, typename... Args> void print_impl(T &&inp, Args &&...args) {
    print_impl(inp);
    print_impl(std::forward<Args>(args)...);
}

#define LOG_ARRAY_WITH_RANGE(arr, start, end)                                          \
    {                                                                                  \
        IO_WITH_INFO << #arr << "[" << start << ":" << end << "]: {";                  \
        for (size_t i = start; i < end; ++i) {                                         \
            IO << arr[i];                                                              \
            if (i != end - 1) {                                                        \
                IO << " ";                                                             \
            }                                                                          \
        }                                                                              \
        IO << "}" << EOL;                                                              \
    }

#define LOG_ARRAY(arr) LOG_ARRAY_WITH_RANGE(arr, 0, arr.size())

#define LOG_ARRAY2D_WITH_RANGE(arr, start1d, end1d, start2d, end2d)                    \
    {                                                                                  \
        IO_WITH_INFO << #arr << "[" << start1d << ":" << end1d << "][" << start2d      \
                     << ":" << end2d << "] {" << EOL;                                  \
        for (size_t i = start1d; i < end1d; ++i) {                                     \
            IO << "    ";                                                              \
            for (size_t j = start2d; j < end2d; ++j) {                                 \
                IO << arr[i][j] << " ";                                                \
            }                                                                          \
            IO << EOL;                                                                 \
        }                                                                              \
        IO << "}" << EOL;                                                              \
    }

#define LOG_ARRAY2D(arr)                                                               \
    LOG_ARRAY2D_WITH_RANGE(arr, 0, arr.size(), 0, (arr.size() > 0 ? arr[0].size() : 0))

#define LOG_EXPRS(...)                                                                 \
    {                                                                                  \
        IO_WITH_INFO << #__VA_ARGS__ << ": ";                                          \
        print_impl(__VA_ARGS__);                                                       \
        IO << EOL;                                                                     \
    }

#define LOG_EXPR(expr)                                                                 \
    { IO_WITH_INFO << #expr << ": " << expr << EOL; }

#define LOG_HEX(expr)                                                                  \
    { IO_WITH_INFO << #expr << ": 0x" << std::hex << expr << EOL; }

#define LOG_BIN(expr)                                                                  \
    { IO_WITH_INFO << #expr << ": 0b" << std::bitset<sizeof(expr) * 8>(expr) << EOL; }

#define LOG_SET(expr)                                                                  \
    {                                                                                  \
        IO_WITH_INFO << #expr << "[" << expr.size() << "] {";                          \
        for (auto iter = expr.begin(); iter != expr.end();) {                          \
            IO << (*iter);                                                             \
            if ((++iter) != expr.end()) {                                              \
                IO << " ";                                                             \
            }                                                                          \
        }                                                                              \
        IO << "}" << EOL;                                                              \
    }

#define LOG_MAP(expr)                                                                  \
    {                                                                                  \
        IO_WITH_INFO << #expr << " {" << EOL;                                          \
        for (auto &&kv : expr) {                                                       \
            IO << "    " << kv.first << ": " << kv.second << EOL;                      \
        }                                                                              \
        IO << "}" << EOL;                                                              \
    }

#define LOG_LIST(head, val)                                                            \
    {                                                                                  \
        IO_WITH_INFO << #head << ": {";                                                \
        auto cur = head;                                                               \
        while (cur) {                                                                  \
            IO << cur->val;                                                            \
            cur = cur->next;                                                           \
            if (cur) {                                                                 \
                IO << " ";                                                             \
            }                                                                          \
        }                                                                              \
        IO << "}" << EOL;                                                              \
    }

#define Vec(type) std::vector<type>
#define Vec2D(type) std::vector<std::vector<type>>

namespace list {

template <typename T> struct ListNode {
    T val;
    ListNode *next;
    ListNode() : next(nullptr) {}
    ListNode(T x) : val(x), next(nullptr) {}
    ListNode(T x, ListNode *next) : val(x), next(next) {}
};

template <typename T> struct ListHelper {
    static inline ListNode<T> *alloc(const std::vector<T> &source) {
        if (source.size() == 0) {
            return nullptr;
        }

        auto head = new ListNode<T>(source[0]);
        auto pre = head;
        for (size_t i = 1; i < source.size(); ++i) {
            auto node = new ListNode<T>(source[i]);
            pre->next = node;
            pre = node;
        }
        return head;
    }

    struct ListDeleter {
        void operator()(ListNode<T> *head) {
            while (head != nullptr) {
                auto cur = head;
                head = head->next;
                delete cur;
            }
        }
    };

    static inline std::unique_ptr<ListNode<T>, ListDeleter>
    build(const std::vector<T> &source) {
        std::unique_ptr<ListNode<T>, ListDeleter> ret{alloc(source)};
        return std::move(ret);
    }

    struct DefaultPrinter {
        std::vector<T> list_vals;
        void operator()(ListNode<T> *node) { list_vals.push_back(node->val); }
        ~DefaultPrinter() { LOG_ARRAY(list_vals); }
    };

    template <typename Visitor = DefaultPrinter>
    static inline void traverse(ListNode<T> *head, const Visitor &f = {}) {
        auto &&nonconst_func = const_cast<Visitor &>(f);
        while (head != nullptr) {
            auto cur = head;
            head = head->next;
            nonconst_func(cur);
        }
    }
};

} // namespace list

namespace tree {

template <typename T> struct Null;

template <> struct Null<int> { static constexpr int value = INT_MIN; };

template <typename T> inline constexpr T null = Null<T>::value;

template <typename T> struct BinaryTreeNode {
    T val;
    BinaryTreeNode *left;
    BinaryTreeNode *right;
    BinaryTreeNode() : left(nullptr), right(nullptr) {}
    BinaryTreeNode(T x) : val(x), left(nullptr), right(nullptr) {}
    BinaryTreeNode(T x, BinaryTreeNode *left, BinaryTreeNode *right)
        : val(x), left(left), right(right) {}
};

template <typename T> struct BinaryTreeHelper {
    static inline BinaryTreeNode<T> *alloc(const std::vector<T> &source) {
        if (source.size() == 0) {
            return nullptr;
        }
        assert(source[0] != null<T>);

        auto root = new BinaryTreeNode<T>(source[0]);
        std::queue<BinaryTreeNode<T> *> helper;
        helper.push(root);

        for (size_t i = 1; i < source.size();) {
            BinaryTreeNode<T> *cur = helper.front();
            helper.pop();
            if (source[i] != null<T>) {
                cur->left = new BinaryTreeNode<T>(source[i]);
                helper.push(cur->left);
            }
            i += 1;
            if (source[i] != null<T>) {
                cur->right = new BinaryTreeNode<T>(source[i]);
                helper.push(cur->right);
            }
            i += 1;
        }
        return root;
    }

    struct TreeDeleter {
        inline void free(BinaryTreeNode<T> *root) {
            if (root == nullptr)
                return;
            if (root->left != nullptr)
                free(root->left);
            if (root->right != nullptr)
                free(root->right);
            delete root;
        }

        void operator()(BinaryTreeNode<T> *root) { free(root); }
    };

    static inline std::unique_ptr<BinaryTreeNode<T>, TreeDeleter>
    build(const std::vector<T> &source) {
        std::unique_ptr<BinaryTreeNode<T>, TreeDeleter> ret{alloc(source)};
        return std::move(ret);
    }

    struct NaivePrinter {
        void operator()(BinaryTreeNode<T> *node) { LOG_EXPR(node->val); }
    };

    struct DefaultPrinter {
        std::vector<T> tree_list;
        void operator()(BinaryTreeNode<T> *node) { tree_list.push_back(node->val); }
        ~DefaultPrinter() { LOG_ARRAY(tree_list); }
    };

    template <typename Visitor = DefaultPrinter>
    static inline void preorder(BinaryTreeNode<T> *root, const Visitor &f = {}) {
        if (root == nullptr) {
            return;
        }
        auto &&nonconst_func = const_cast<Visitor &>(f);
        nonconst_func(root);
        preorder(root->left, f);
        preorder(root->right, f);
    }

    template <typename Visitor = DefaultPrinter>
    static inline void inorder(BinaryTreeNode<T> *root, const Visitor &f = {}) {
        if (root == nullptr) {
            return;
        }
        auto &&nonconst_func = const_cast<Visitor &>(f);
        inorder(root->left, f);
        nonconst_func(root);
        inorder(root->right, f);
    }

    template <typename Visitor = DefaultPrinter>
    static inline void postorder(BinaryTreeNode<T> *root, const Visitor &f = {}) {
        if (root == nullptr) {
            return;
        }
        auto &&nonconst_func = const_cast<Visitor &>(f);
        postorder(root->left, f);
        postorder(root->right, f);
        nonconst_func(root);
    }

    template <typename Visitor = DefaultPrinter>
    static inline void bfs(BinaryTreeNode<T> *root, const Visitor &f = {}) {
        if (root == nullptr) {
            return;
        }
        auto &&nonconst_func = const_cast<Visitor &>(f);
        std::queue<BinaryTreeNode<T> *> helper;
        helper.push(root);
        helper.push(nullptr);

        while (!helper.empty()) {
            auto cur = helper.front();
            helper.pop();
            if (cur == nullptr) {
                if (!helper.empty()) {
                    helper.push(nullptr);
                }
                continue;
            } else {
                nonconst_func(cur);
                if (cur->left) {
                    helper.push(cur->left);
                }
                if (cur->right) {
                    helper.push(cur->right);
                }
            }
        }
    }
};

} // namespace tree

using namespace std;

#endif