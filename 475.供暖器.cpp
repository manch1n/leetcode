/*
 * @lc app=leetcode.cn id=475 lang=cpp
 *
 * [475] 供暖器
 */
#include <algorithm>
#include <vector>
using namespace std;
class Solution
{
public:
    int findRadius(vector<int> &houses, vector<int> &heaters)
    {
        // int horse_size = houses.size();
        // int heater_size = heaters.size();
        // int radius = 0;
        // int count=0;
        // while (1)
        // {
        //     // if(heaters[0]-houses[horse_size-1]>radius)
        //     // {
        //     //     radius+=1;
        //     //     continue;
        //     // }
        //     for (int i = 0; i < heater_size; ++i)
        //     {
        //         int r=heaters[i]+radius;
        //         int l=heaters[i]-radius;
        //         if(r<houses[0]||l>houses[horse_size-1])
        //         {
        //             break;
        //         }
        //         for(auto& n:houses)
        //         {
        //             if(n<0) continue;
        //             if(n>=l&&n<=r) 
        //             {
        //                 n=-n;
        //                 count+=1;
        //             }
        //         }
        //     }
        //     bool completed = false;
        //     if(count==horse_size)
        //     {
        //         return radius;
        //     }
        //     radius += 1;
        // }
        // return 0;
        sort(heaters.begin(),heaters.end());
        int ans=0;
        //思路：
        //对于每座房子，有前后两个供暖器(只有一个供暖器的情况另外判断)，寻找它们之间的较小距离，并与当前最大半径比较更新即可
        for(int i=0;i<houses.size();i++)
        {
            int cur=INT_MAX;
            // lower_bound 返回第一个大于等于这个元素的迭代器
            //此时larger就是这座房子右边的供暖器
            //使用*larger来取值,或者heaters[larger-heaters.begin()]
            auto larger = lower_bound(heaters.begin(),heaters.end(),houses[i]);
            if(larger!=heaters.end())
            {
                //如果存在的话 那么就计算它们之间的距离
                cur=*larger-houses[i];
            }
            //如果这个元素没有小于最开始的元素 那么意味着它左边也有一个供暖器
            if(larger!=heaters.begin())
            {
                //左边供暖器的位置就是当前larger位置-1
                auto smaller=larger-1;
                //使用*smaller来取得这个值,更新它们之间的较小值
                cur=min(cur,houses[i]-*smaller);
            }
            ans=max(cur,ans);
        }
        return ans;
    }
};


//23333 果然timeout了
// × Time Limit Exceeded
//   × 10/30 cases passed (N/A)
//   × testcase: '[282475249,622650073,984943658,144108930,470211272,101027544,457850878,458777923]\n[823564440,115438165,784484492,74243042,114807987,137522503,441282327,16531729,823378840,143542612]'
//   × answer: 
//   × expected_answer: 
//   × stdout: