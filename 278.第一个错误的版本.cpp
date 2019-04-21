/*
 * @lc app=leetcode.cn id=278 lang=cpp
 *
 * [278] 第一个错误的版本
 *
 * https://leetcode-cn.com/problems/first-bad-version/description/
 *
 * algorithms
 * Easy (30.01%)
 * Total Accepted:    15.5K
 * Total Submissions: 50.9K
 * Testcase Example:  '5\n4'
 *
 * 
 * 你是产品经理，目前正在带领一个团队开发新的产品。不幸的是，你的产品的最新版本没有通过质量检测。由于每个版本都是基于之前的版本开发的，所以错误的版本之后的所有版本都是错的。
 * 
 * 假设你有 n 个版本 [1, 2, ..., n]，你想找出导致之后所有版本出错的第一个错误的版本。
 * 
 * 你可以通过调用 bool isBadVersion(version) 接口来判断版本号 version
 * 是否在单元测试中出错。实现一个函数来查找第一个错误的版本。你应该尽量减少对调用 API 的次数。
 * 
 * 示例:
 * 
 * 给定 n = 5，并且 version = 4 是第一个错误的版本。
 * 
 * 调用 isBadVersion(3) -> false
 * 调用 isBadVersion(5) -> true
 * 调用 isBadVersion(4) -> true
 * 
 * 所以，4 是第一个错误的版本。 
 * 
 */
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);


//回溯
class Solution {
public:
    int firstBadVersion(int n) {
        //从尾开始回溯似乎有点久。这应该是二叉搜素。
        // int base=1;
        // int i;
        // for(i=n;i>=1;i-=base)
        // {
        //     base*=2;
        //     if(isBadVersion(i)==false)
        //     {
        //         break;
        //     }
        // }
        // for(int j=i+1;;++j)
        // {
        //     if(isBadVersion(j)==true)
        //         return j;
        // }
        // return 1;
        if(n==1) return 1;
        long i=(1+static_cast<long>(n))/2;
        while(1)
        {
            if(isBadVersion(i)==false)
            {
                if(i==(i+n)/2)
                {
                    return i+1;
                }
                else
                {
                    i=(i+n)/2;
                }
            }
            else break;
        }
        for(int j=i-1;j>=1;--j)
        {
            if(isBadVersion(j)==false) return j+1;
        }
        return 1;
    }
};

// √ Accepted
//   √ 22/22 cases passed (864 ms)
//   √ Your runtime beats 5.34 % of cpp submissions
//   √ Your memory usage beats 43.31 % of cpp submissions (8.1 MB)


/*! 很奇怪哟，两种方法都不太行 */
// √ Accepted
//   √ 22/22 cases passed (944 ms)
//   √ Your runtime beats 5.34 % of cpp submissions
//   √ Your memory usage beats 72.57 % of cpp submissions (8 MB