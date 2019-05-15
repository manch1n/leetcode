/*
 * @lc app=leetcode.cn id=605 lang=cpp
 *
 * [605] 种花问题
 */
#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        int size = flowerbed.size();
        int result = 0;
        for (int i = 0; i < size; ++i)
        {
            if (i == 0)
            {
                if (size >= 2)
                {
                    if (flowerbed[0] == 0 && flowerbed[1] == 0)
                    {
                        flowerbed[0] = 1;
                        result += 1;
                    }
                }
                else
                {
                    if (flowerbed[0] == 0)
                    {
                        flowerbed[0] = 1;
                        result += 1;
                    }
                }
            }
            else if (i == size - 1)
            {
                if (flowerbed[size - 2] == 0 && flowerbed[size - 1] == 0)
                {
                    flowerbed[i] = 1;
                    result += 1;
                }
            }
            else
            {
                if (flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0)
                {
                    if (flowerbed[i] == 0)
                    {
                        flowerbed[i] = 1;
                        result += 1;
                    }
                }
            }
        }
        if (result >= n)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

// √ Accepted
//   √ 123/123 cases passed (24 ms)
//   √ Your runtime beats 93.75 % of cpp submissions
//   √ Your memory usage beats 81.92 % of cpp submissions (10.3 MB)
