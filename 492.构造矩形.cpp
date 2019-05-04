/*
 * @lc app=leetcode.cn id=492 lang=cpp
 *
 * [492] 构造矩形
 */
#include <vector>
using namespace std;
class Solution
{
public:
    // vector<int> construct(int area,int l,int w)
    // {
    //     int design=l*w;
    //     if(design==area) return vector<int>{l,w};
    //     else if(design>area)
    //     {
    //         return construct(area,l,--w);
    //     }
    //     else
    //     {
    //         return construct(area,++l,w);
    //     }

    // }
    vector<int> constructRectangle(int area)
    {
        // int l=sqrt(area);
        // int w=sqrt(area);
        // return construct(area,l,w);
        int l = sqrt(area);
        int w = sqrt(area);
        while (1)
        {
            int estimate = l * w;
            if (estimate == area)
            {
                return vector<int>{l, w};
            }
            else if (estimate > area)
            {
                w--;
            }
            else
            {
                l++;
            }
        }
        return vector<int>{0, 0};
    }
};

// √ Accepted
//   √ 50/50 cases passed (28 ms)
//   √ Your runtime beats 40.08 % of cpp submissions
//   √ Your memory usage beats 82.73 % of cpp submissions (8.2 MB)

//用了递归栈溢出，emmm改成循环好了。
// × Runtime Error
//   × 22/50 cases passed (N/A)
//   × error: AddressSanitizer: stack-overflow on address 0x7ffd8808ffe0 (pc 0x000000411c73 bp 0x7ffd88090100 sp 0x7ffd8808ffe0 T0)
//   × error: AddressSanitizer:DEADLYSIGNAL
// =================================================================
// ==30==ERROR: AddressSanitizer: stack-overflow on address 0x7ffd8808ffe0 (pc 0x000000411c73 bp 0x7ffd88090100 sp 0x7ffd8808ffe0 T0)

// ==30==ABORTING
//   × testcase: '9999998'
//   × answer:
//   × expected_answer:
//   × stdout: