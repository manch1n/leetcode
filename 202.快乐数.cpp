/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 *
 * https://leetcode-cn.com/problems/happy-number/description/
 *
 * algorithms
 * Easy (52.42%)
 * Total Accepted:    15.6K
 * Total Submissions: 29.7K
 * Testcase Example:  '19'
 *
 * 编写一个算法来判断一个数是不是“快乐数”。
 * 
 * 一个“快乐数”定义为：对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和，然后重复这个过程直到这个数变为 1，也可能是无限循环但始终变不到
 * 1。如果可以变为 1，那么这个数就是快乐数。
 * 
 * 示例: 
 * 
 * 输入: 19
 * 输出: true
 * 解释: 
 * 1^2 + 9^2 = 82
 * 8^2 + 2^2 = 68
 * 6^2 + 8^2 = 100
 * 1^2 + 0^2 + 0^2 = 1
 * 
 * 
 */
#include <vector>
using namespace std;
class Solution
{
public:
    bool isHappy(int n)
    {
        vector<int> nums;
        while (1)
        {
            int result = 0;
            while (n)
            {
                result += (n % 10) * (n % 10);
                n /= 10;
            }
            if (result == 1)
                return true;
            //if find repeat return false;
            if (find(nums.cbegin(), nums.cend(), result) != nums.cend())
                return false;
            nums.push_back(result);
            n = result;
            //if result is 10^k return true
            while (result)
            {
                if (result == 1)
                    return true;
                if (result % 10 != 0)
                    break;
                result /= 10;
            }
        }
    }
};
// √ Accepted
//   √ 401/401 cases passed (8 ms)
//   √ Your runtime beats 96.89 % of cpp submissions
//   √ Your memory usage beats 60.63 % of cpp submissions (8.2 MB)