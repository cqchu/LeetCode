* 0004, "Median of Two Sorted Arrays": 设计index pointor</br>
* 0010, "Regular Expression Matching": 正则式匹配问题, 要考虑的情况挺多的, 故而用递归间接的遍历了这些情况而不用写很多判定代码</br>
* 0011, "Container With Most Water": 也是一个index pointor</br>
* 0015, "3 Sum": 先fix一个数, 转化为2 Sum问题, 用index pointor解决</br>
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
