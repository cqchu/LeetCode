#ifndef __INCLUDES_H
#define __INCLUDES_H

#include <algorithm>
#include <climits>
#include <cmath>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#define IO std::cout
#define IO_WITH_INFO IO << __FILE__ << ":" << __LINE__ << " -> "

#define LOG_ARRAY_WITH_RANGE(arr, start, end)                                  \
    {                                                                          \
        IO_WITH_INFO << #arr << "[" << start << ":" << end << "]: {";          \
        for (size_t i = start; i < end; ++i) {                                 \
            IO << arr[i];                                                      \
            if (i != end - 1) {                                                \
                IO << " ";                                                     \
            }                                                                  \
        }                                                                      \
        IO << "}" << std::endl;                                                \
    }

#define LOG_ARRAY(arr) LOG_ARRAY_WITH_RANGE(arr, 0, arr.size())

#define LOG_ARRAY2D_WITH_RANGE(arr, start1d, end1d, start2d, end2d)            \
    {                                                                          \
        IO_WITH_INFO << #arr << "[" << start1d << ":" << end1d << "]["         \
                     << start2d << ":" << end2d << "] {" << std::endl;         \
        for (size_t i = start1d; i < end1d; ++i) {                             \
            IO << "    ";                                                      \
            for (size_t j = start2d; j < end2d; ++j) {                         \
                IO << arr[i][j] << " ";                                        \
            }                                                                  \
            IO << std::endl;                                                   \
        }                                                                      \
        IO << "}" << std::endl;                                                \
    }

#define LOG_ARRAY2D(arr)                                                       \
    LOG_ARRAY2D_WITH_RANGE(arr, 0, arr.size(), 0,                              \
                           (arr.size() > 0 ? arr[0].size() : 0))

template <typename T> void print_impl(T &&inp) { IO << inp << " "; }

template <typename T, typename... Args> void print_impl(T &&inp, Args... args) {
    print_impl(inp);
    print_impl(std::forward<Args>(args)...);
}

#define LOG_VAR(...)                                                           \
    {                                                                          \
        print_impl(__VA_ARGS__);                                               \
        IO << std::endl;                                                       \
    }

#define LOG_MAP(dict)                                                          \
    {                                                                          \
        IO_WITH_INFO << #dict << " {" << std::endl;                            \
        for (auto &&kv : dict) {                                               \
            IO << "    " << kv.first << ": " << kv.second << std::endl;        \
        }                                                                      \
        IO << "}" << std::endl;                                                \
    }

#define LOG_LIST(head, val)                                                    \
    {                                                                          \
        IO_WITH_INFO << #head << ": {";                                        \
        auto cur = head;                                                       \
        while (cur) {                                                          \
            IO << cur->val;                                                    \
            cur = cur->next;                                                   \
            if (cur) {                                                         \
                IO << " ";                                                     \
            }                                                                  \
        }                                                                      \
        IO << "}" << std::endl;                                                \
    }

#endif