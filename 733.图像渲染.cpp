/*
 * @lc app=leetcode.cn id=733 lang=cpp
 *
 * [733] 图像渲染
 */
#include <vector>
using namespace std;
class Solution
{
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {

        int old = image[sr][sc];
        if (old == newColor)
            return image;
        image[sr][sc] = newColor;
        if (sr - 1 >= 0 && image[sr - 1][sc] == old)
            image = floodFill(image, sr - 1, sc, newColor);
        if (sc - 1 >= 0 && image[sr][sc - 1] == old)
            image = floodFill(image, sr, sc - 1, newColor);
        if (sr + 1 < image.size() && image[sr + 1][sc] == old)
            image = floodFill(image, sr + 1, sc, newColor);
        if (sc + 1 < image[sr].size() && image[sr][sc + 1] == old)
            image = floodFill(image, sr, sc + 1, newColor);
        return image;
    }
};

// √ Accepted
//   √ 277/277 cases passed (76 ms)
//   √ Your runtime beats 11.75 % of cpp submissions
//   √ Your memory usage beats 71.56 % of cpp submissions (10.9 MB)