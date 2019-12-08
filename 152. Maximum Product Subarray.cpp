//link: https://leetcode-cn.com/problems/maximum-product-subarray/submissions/
//leetcode include headers:
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxProduct(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) {                   //dp[i]=max(dp[i-1]*nums[i],nums[i])
        return 0;
    }
    int dpMax = nums[0];
    int dpMin = nums[0];
    int max = nums[0];
    for (int i = 1; i < n; i++) {
        int preMax = dpMax;
        dpMax = std::max(dpMin * nums[i], std::max(dpMax * nums[i], nums[i]));
        dpMin = std::min(dpMin * nums[i], std::min(preMax * nums[i], nums[i]));
        max = std::max(max, dpMax);
        }
        return max;
    }
};