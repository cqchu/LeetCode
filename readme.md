### usage
```bash
python format.py                        # format all *.hpp file
python gen_template.py -i problem-id    # generate code template
```

### questions

* 0004, "Median of Two Sorted Arrays": 设计index pointor</br>
* 0010, "Regular Expression Matching": 正则式匹配问题, 要考虑的情况挺多的, 故而用递归间接的遍历了这些情况而不用写很多判定代码</br>
* 0011, "Container With Most Water": 也是一个index pointor</br>
* 0015, "3 Sum": 先fix一个数, 转化为2 Sum问题, 用index pointor解决</br>
* 0019, "Remove N-th node from the end": 可以用两个指针来解决，第一个指针先走n步</br>
* 0023, "Merge k Sorted Lists": 这种问题可以用分治算法来做</br>
* 0030, "Substring with Concatenation of All Words": 字符串问题中的滑动窗口方法, 以及用existFlag或者说是existDictionary这种以空间换时间的思想</br>
* 0032, "Longest Valid Parentheses": 类似于最长子串和, 但更难一些，dp更新的条件更难找</br>
* 0039, "Combination Sum": 这种题都是DFS求解, 本质上都是暴力求解</br>
* 0040, "First Missing Positive": 类似与Counting Sort, 都是借用Index表示一些信息</br>
* 0042, "Trapping Rain Water": leetcode题解中提供了一种巧妙的做法</br>
* 0044, "Wildcard Matching": 一个典型的动归题, 非常便于理解动归, 但题解中有双指针的方法</br>
* 0047, "Permutations II": 其中swap()使用的很精髓</br>
* 0049, "Group Anagrams": 两种方法, 一种需要排序, 一种是Cnt编码, 编程珠玑里也有提到, 后者时间复杂度更低</br>
* 0050, "Pow(x, n)": 里面降低时间复杂度的方法需要注意</br>
* 0051, "Maximum Subarray": 同时可以用分治和动归两种方法来解, 动归需要注意把握状态变化</br>
* 0062, "Unique Paths": 可以用递归解, 但是超时了, 所以用0050题的方法进行优化, 即使用DP, 同时这题中还用了2D DP->1D DP</br>
* 0075, "Sort Colors": 类似于Count Sort, 然后第二种方法挺有意思的</br>
* 0076, "Minimum Window Substring": 滑动窗口法, 注意左右移动指针的规则</br>
* 0085, "Maximal Rectangle": 将2D问题转换为1D问题(Problem 0084), 1D问题使用栈来解决</br>
* 0087, "Scramble String": 用递归的形式进行枚举, 并进行剪枝</br>
* 0095, "Unique Binary Search Trees": 也没啥思想, 就是要抓住规律, 递归就完事了</br>
* 0097, "Interleaving String": 还是用DP来优化递归, 然而我还我没写出来, 我好菜啊</br>
* 0099, "Recover Binary Search Tree": 很多树的问题直接在树中不好解决可以将之转化成在序列中</br>
* 0113, "Path Sum II": 这题与0039题类似, 这种递归求某个符合条件的子集的问题都可以加入stack简化问题</br>
* 0115, "Distinct Subsequences": 一道朴实无华且枯燥的动归题, 遇到这种问题可以自己手写一个例子的dp数组, 然后找状态转移方程</br>
* 0123, "Best Time to Buy and Sell Stock III": 好好理解一下什么叫动归就是带缓存的递归</br>
* 0126, "Word Ladder II": 把这个问题抽象成无向无权图中最短路径问题, 然后用双向BFS降低搜索空间的复杂度来解. 同时这里判断两个节点连接的方式是用unordered\_set来做</br>
* 0128, "Longest Consecutive Sequence": 类似于Counting Sort的方法, 不同的是这里出于节约空间的考量把把原始数据放到一个unordered map中, 然后再在这unordered map中解决这个问题</br>
* 0131, "Palindrome Partitioning": 就和之前找数组的全排列横向，用回溯=递归+栈来解</br>
* 0132, "Palindrome Partitioning II": 一个例子分四个版本详细说明什么叫`DP = Recurse + Buffer`</br>
* 0135, "Candy": 和42题一模一样，这种找一个数组内极大极小值再做操作的题都是左右两遍遍历解决</br>
* 0136, "Single Number": 异或操作找重复数字，往事如烟</br>
* 0142, "Linked List Cycle II": 环形链表，快慢指针，需要注意的是因为快指针速度是慢指针的两倍，所以慢指针最多只跑一圈就会被快指针套圈</br>
* 0146, "LRU Cache": 用计数器的方式决定是否真的进行替换</br>
* 0148, "Sort List": 典型的 devide and conquer</br>
* 0149, "Max Points on a Line": 就硬枚举，毫无技巧，就当长个见识背个题吧</br>
* 0152, "Maximum Product Subarray": 整两个dp array交错着来</br>
* 0164, "Maximum Gap": 时间复杂度O(n)，首先要想到桶排序，桶排序是基于统计而非基于比较的，时间复杂度较低而空间复杂度较高</br>
* 0169, "Majority Element": 很精妙，消元</br>
* 0174, "Dungeon Game": 倒序dp，因为有加血的过程，正向dp会丢失信息</br>
* 0187, "Repeated DNA Sequences": 更低overhead的记录方法</br>
* 0188, "Best Time to Buy and Sell Stock IV": 没太看懂</br>
* 0207, "Course Schedule": 第一眼看起来是个拓扑排序，但这一题我们只需要判断图中是否有环，可以dfs来做</br>
* 0212, "Word Search II": 把 words 用字典树保存，然后对 board 做 DFS，每次 DFS 之后看看当前 DFS 序列在字典树中是否有，有的话继续 DFS，否则返回</br>
* 0215, "Kth Largest Element in an Array": counting sort 或者优先队列</br>
* 0220, "Contains Duplicate III": 合理用一些其他的数据结构而不是自己硬来</br>
* 0221, "Maximal Square": 2D DP -> 1D DP</br>
* 0229, "Majority Element II": 还是对这种投票计数的方式没理解清楚</br>