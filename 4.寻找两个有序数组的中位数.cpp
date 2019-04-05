/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个有序数组的中位数
 *
 * https://leetcode-cn.com/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (34.23%)
 * Total Accepted:    44.5K
 * Total Submissions: 129.9K
 * Testcase Example:  '[1,3]\n[2]'
 *
 * 给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。
 * 
 * 请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。
 * 
 * 你可以假设 nums1 和 nums2 不会同时为空。
 * 
 * 示例 1:
 * 
 * nums1 = [1, 3]
 * nums2 = [2]
 * 
 * 则中位数是 2.0
 * 
 * 
 * 示例 2:
 * 
 * nums1 = [1, 2]
 * nums2 = [3, 4]
 * 
 * 则中位数是 (2 + 3)/2 = 2.5
 * 
 * 
 */
#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len_1=nums1.size();
        int len_2=nums2.size();
        bool odd=false;
        int position;
        if((len_1+len_2)%2==0)
        {
            position=(len_1+len_2)/2;
        }
        else
        {
            odd=true;
            position=(len_1+len_2)/2+1;
        }
        if(len_1==0)
        {
            if(odd)
            {
                return nums2[position-1];
            }
            else
            {
                return (nums2[position-1]+nums2[position])/2;
            }
        }
        else if(len_2==0)
        {
            if(odd)
            {
                return nums1[position-1];
            }
            else
            {
                return (nums1[position-1]+nums1[position])/2;
            }
        }
        else
        {
            int i=0,j=0;
            while(len_1&&len_2&&(i+j)!=position-1)
            {
                while((nums1[i]<=nums2[j])&&(i+j)!=position-1) i++;
                while((nums1[i]<=nums2[j])&&(i+j)!=position-1) j++;
            }
            if((i+j)==position-1)
            {
                if(!odd)
                {
                    return (nums1[i]+nums2[j])/2;
                }
                else
                {
                    return 
                }
                
            }
        }
        
    }
};

