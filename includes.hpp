#ifndef __INCLUDES_H
#define __INCLUDES_H

#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <climits>
#include <cmath>
#include <cstdarg>
#include <cstring>
#include <deque>
#include <functional>
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

/*********************** Assert ***********************/

namespace assert_utils {

class AssertHelper {
    inline static std::string svsprintf(const char *fmt, va_list ap_orig) {
        int size = 100;
        char *p;

        if ((p = (char *)malloc(size)) == nullptr)
            goto err;

        for (;;) {
            va_list ap;
            va_copy(ap, ap_orig);
            int n = vsnprintf(p, size, fmt, ap);
            va_end(ap);

            if (n < 0)
                goto err;

            if (n < size) {
                std::string rst(p);
                free(p);
                return rst;
            }

            size = n + 1;

            char *np = (char *)realloc(p, size);
            if (!np) {
                free(p);
                goto err;
            } else
                p = np;
        }

    err:
        fprintf(stderr, "could not allocate memory for svsprintf; fmt=%s\n", fmt);
        __builtin_trap();
    }

    inline static std::string ssprintf(const char *fmt, ...) {
        va_list ap;
        va_start(ap, fmt);
        auto rst = svsprintf(fmt, ap);
        va_end(ap);
        return rst;
    }

public:
    inline static void assert_failed_log(const char *file, int line, const char *func,
                                         const char *expr, const char *msg_fmt, ...) {
        std::string msg =
            ssprintf("`%s' should be true at %s:%d: %s", expr, file, line, func);
        if (msg_fmt) {
            va_list ap;
            va_start(ap, msg_fmt);
            msg.append("\nextra message: ");
            msg.append(svsprintf(msg_fmt, ap));
            va_end(ap);
        }
        printf("%s\n", msg.c_str());
    }
};

} // namespace assert_utils

#define cqassert(expr, msg...)                                                         \
    if (!(expr)) {                                                                     \
        ::assert_utils::AssertHelper::assert_failed_log(                               \
            __FILE__, __LINE__, __PRETTY_FUNCTION__, #expr, ##msg);                    \
        assert((expr));                                                                \
    }

/*********************** IO ***********************/

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

#define LOG_STACK(expr)                                                                \
    {                                                                                  \
        auto copied = expr;                                                            \
        IO_WITH_INFO << #expr << "[" << 0 << ":" << copied.size() << "]: {";           \
        while (!copied.empty()) {                                                      \
            IO << copied.top();                                                        \
            copied.pop();                                                              \
            if (!copied.empty()) {                                                     \
                IO << " ";                                                             \
            }                                                                          \
        }                                                                              \
        IO << "}" << EOL;                                                              \
    }

#define LOG_QUEUE(expr)                                                                \
    {                                                                                  \
        auto copied = expr;                                                            \
        IO_WITH_INFO << #expr << "[" << 0 << ":" << copied.size() << "]: {";           \
        while (!copied.empty()) {                                                      \
            IO << copied.front();                                                      \
            copied.pop();                                                              \
            if (!copied.empty()) {                                                     \
                IO << " ";                                                             \
            }                                                                          \
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

/*********************** LIST ***********************/

namespace cqlist {

template <typename T> struct ListNode {
    T val;
    ListNode *next;
    ListNode() : next(nullptr) {}
    ListNode(T x) : val(x), next(nullptr) {}
    ListNode(T x, ListNode *next) : val(x), next(next) {}
};

template <typename T> struct ListHelper {
private:
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

public:
    using NodePtr = ListNode<T> *;

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

} // namespace cqlist

/*********************** Tree ***********************/

namespace cqtree {

template <typename T> struct Null;

template <> struct Null<int> { static constexpr int value = INT_MIN; };
template <> struct Null<float> { static constexpr float value = NAN; };

template <typename T> constexpr T null = Null<T>::value;

template <typename T> struct BinaryTreeNode {
    T val;
    BinaryTreeNode *left;
    BinaryTreeNode *right;
    BinaryTreeNode() : left(nullptr), right(nullptr) {}
    BinaryTreeNode(T x) : val(x), left(nullptr), right(nullptr) {}
    BinaryTreeNode(T x, BinaryTreeNode *left, BinaryTreeNode *right)
        : val(x), left(left), right(right) {}
};

template <typename T, T nullval = null<T>> struct BinaryTreeHelper {
private:
    static inline BinaryTreeNode<T> *alloc(const std::vector<T> &source) {
        if (source.size() == 0) {
            return nullptr;
        }
        cqassert(source[0] != nullval, "invalid tree");

        auto root = new BinaryTreeNode<T>(source[0]);
        std::queue<BinaryTreeNode<T> *> helper;
        helper.push(root);

        for (size_t i = 1; i < source.size();) {
            BinaryTreeNode<T> *cur = helper.front();
            helper.pop();
            if (source[i] != nullval) {
                cqassert(cur != nullptr, "invalid tree");
                cur->left = new BinaryTreeNode<T>(source[i]);
                helper.push(cur->left);
            } else {
                helper.push(nullptr);
            }
            i += 1;
            if (i >= source.size()) {
                break;
            }
            if (source[i] != nullval) {
                cqassert(cur != nullptr, "invalid tree");
                cur->right = new BinaryTreeNode<T>(source[i]);
                helper.push(cur->right);
            } else {
                helper.push(nullptr);
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

public:
    using NodePtr = BinaryTreeNode<T> *;

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

} // namespace cqtree

/*********************** Benchmark ***********************/

namespace cqbench {

class TimeRecords {
    using NanoRecord = std::pair<size_t, std::chrono::nanoseconds>;
    std::unordered_map<std::string, NanoRecord> nano_records;
    TimeRecords() = default;

    enum class TimeUnit { ns, us, ms, s };

    void log_record_impl(TimeUnit tu) const {
        std::cout << "Bench Time Records {\n";
        for (auto &&kv : nano_records) {
            std::cout << "    " << kv.first << ": ";
            size_t iter_times = kv.second.first,
                   nanoseconds = static_cast<size_t>(kv.second.second.count());
            switch (tu) {
            case TimeUnit::ns:
                std::cout << std::fixed
                          << nanoseconds / static_cast<long double>(iter_times)
                          << " ns\n";
                break;
            case TimeUnit::us:
                std::cout << std::fixed
                          << nanoseconds / static_cast<long double>(1e3 * iter_times)
                          << " us\n";
                break;
            case TimeUnit::ms:
                std::cout << std::fixed
                          << nanoseconds / static_cast<long double>(1e6 * iter_times)
                          << " ms\n";
                break;
            case TimeUnit::s:
                std::cout << std::fixed
                          << nanoseconds / static_cast<long double>(1e9 * iter_times)
                          << " s\n";
                break;
            default:
                cqassert(false, "error time unit");
            }
        }
        std::cout << "}" << std::endl;
    }

public:
    inline static TimeRecords &inst() {
        static TimeRecords time_stats;
        return time_stats;
    }

    bool add_record_allow_fallible(const std::string &hint, size_t iter_times,
                                   const std::chrono::nanoseconds &record) {
        auto ret = nano_records.emplace(hint, NanoRecord{iter_times, record.count()});
        return ret.second;
    }

    void add_record(const std::string &hint, size_t iter_times,
                    const std::chrono::nanoseconds &record) {
        auto success = add_record_allow_fallible(hint, iter_times, record);
        cqassert(success, "%s is already in time records", hint.c_str());
    }

    void log_record_ns() const { log_record_impl(TimeUnit::ns); }

    void log_record_us() const { log_record_impl(TimeUnit::us); }

    void log_record_ms() const { log_record_impl(TimeUnit::ms); }

    void log_record_s() const { log_record_impl(TimeUnit::s); }
};

} // namespace cqbench

#define TimeRecordsInst ::cqbench::TimeRecords::inst()

#define TimeBenchmark(hint, warm_iter, bench_iter, sync_func, log, workload_exprs)     \
    {                                                                                  \
        std::function<void(void)> synchronizer{sync_func};                             \
        for (size_t _time_bench_iter = 0; _time_bench_iter < warm_iter;                \
             ++_time_bench_iter) {                                                     \
            workload_exprs;                                                            \
        }                                                                              \
        if (sync_func != nullptr)                                                      \
            synchronizer();                                                            \
        auto start = std::chrono::high_resolution_clock::now();                        \
        for (size_t _time_bench_iter = 0; _time_bench_iter < bench_iter;               \
             ++_time_bench_iter) {                                                     \
            workload_exprs;                                                            \
        }                                                                              \
        if (sync_func != nullptr)                                                      \
            synchronizer();                                                            \
        auto end = std::chrono::high_resolution_clock::now();                          \
        auto duration =                                                                \
            std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);         \
        TimeRecordsInst.add_record(std::string{hint}, bench_iter, duration);           \
        if (log) {                                                                     \
            std::cout << hint << ": " << static_cast<size_t>(duration.count())         \
                      << " ns for " << bench_iter << " iter" << std::endl;             \
        }                                                                              \
    }

/*********************** Alias ***********************/
template <typename T> using Vec = std::vector<T>;
template <typename T> using Vec2D = std::vector<std::vector<T>>;

using namespace std;

#endif