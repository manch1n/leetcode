/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 *
 * https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/description/
 *
 * algorithms
 * Easy (49.07%)
 * Total Accepted:    38.7K
 * Total Submissions: 78.7K
 * Testcase Example:  '[7,1,5,3,6,4]'
 *
 * 给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。
 * 
 * 如果你最多只允许完成一笔交易（即买入和卖出一支股票），设计一个算法来计算你所能获取的最大利润。
 * 
 * 注意你不能在买入股票前卖出股票。
 * 
 * 示例 1:
 * 
 * 输入: [7,1,5,3,6,4]
 * 输出: 5
 * 解释: 在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
 * ⁠    注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格。
 * 
 * 
 * 示例 2:
 * 
 * 输入: [7,6,4,3,1]
 * 输出: 0
 * 解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。
 * 
 * 
 */

#include <vector>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        // if(prices.size()==0)   //O(n^2)的算法，果然timeout呢。
        // {
        //     return 0;
        // }
        // int max=0;
        // int s=prices.size();
        // for(int i=0;i<s-1;i++)
        //     for(int j=i+1;j<s;j++)
        //     {
        //         if(prices[j]-prices[i]>max) max=prices[j]-prices[i];
        //     }
        // return max;

        //这种解法记得在最大子序和做过
        if (prices.size() <= 1)
            return 0;
        int current = 0;
        int max = 0;
        int size = prices.size();
        for (int i = 0; i < size - 1; i++)
        {
            current += prices[i + 1] - prices[i];
            if (current < 0)
                current = 0;
            if (current > max)
                max = current;
        }
        return max;
    }
};

// √ Accepted
//   √ 200/200 cases passed (12 ms)
//   √ Your runtime beats 96.1 % of cpp submissions
//   √ Your memory usage beats 55.23 % of cpp submissions (9.4 MB)