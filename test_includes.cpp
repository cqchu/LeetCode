#include "includes.hpp"

void test_list() {
    using namespace cqlist;
    using StrList = ListHelper<std::string>;

    std::vector<std::string> strs = {"str1", "str2", "str3"};
    auto list_strs = StrList::build(strs);
    StrList::traverse(list_strs.get());

    struct AddPrefix {
        void operator()(ListNode<std::string>* node) {
            node->val = std::string("pre_") + node->val;
        }
    };
    StrList::traverse<AddPrefix>(list_strs.get());
    StrList::traverse(list_strs.get());
}

void test_tree() {
    using namespace cqtree;
    using IntBinTree = BinaryTreeHelper<int, I32Null>;
    std::vector<int> vi = {1, I32Null, 3, I32Null, I32Null, I32Null, 4, I32Null, I32Null, I32Null, I32Null, I32Null, I32Null, 5, 6};
    auto tree = IntBinTree::build(vi);
    struct AddOne {
        void operator()(IntBinTree::NodePtr ptr) {
            ptr->val += 1;
        }
    };
    IntBinTree::bfs(tree.get());
    IntBinTree::inorder(tree.get());
    IntBinTree::inorder<AddOne>(tree.get());
    IntBinTree::preorder(tree.get());
    IntBinTree::postorder(tree.get());
}

void test_bench() {
    auto matmul = [](Vec2D<float> lhs, Vec2D<float> rhs) -> Vec2D<float> {
        // m*n * n*k = m*k
        size_t m = lhs.size();
        size_t n = lhs[0].size();
        size_t k = rhs[0].size();
        Vec2D<float> res(m, Vec<float>(k, 0.f));
        for (size_t im=0; im<m; ++im) {
            for (size_t ik=0; ik<k; ++ik) {
                for (size_t in=0; in < n; ++in) {
                    res[im][ik] += lhs[im][in] * rhs[in][ik];
                }
            }
        }
        return res;
    };

    size_t m = 256, n = 64, k = 128;
    Vec2D<float> lhs(m, Vec<float>(n, 0.5f)), rhs(n, Vec<float>(k, -0.5f));

    TimeBenchmark("matmul", 10, 100, nullptr, true, {
        auto ret = matmul(lhs, rhs);
    });
    TimeRecordsInst.log_record_s();
    TimeRecordsInst.log_record_ms();
    TimeRecordsInst.log_record_us();
    TimeRecordsInst.log_record_ns();
}

int main(void) {
    test_list();
    test_tree();
    test_bench();
}