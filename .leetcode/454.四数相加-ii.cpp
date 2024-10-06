/*
 * @lc app=leetcode.cn id=454 lang=cpp
 *
 * [454] 四数相加 II
 * 一刷:2024-10-2
 */

#include <vector>
#include <unordered_map>
using namespace std;

// @lc code=start
class Solution
{
public:
    int fourSumCount(vector<int> &nums1, vector<int> &nums2,
                     vector<int> &nums3, vector<int> &nums4) 
    {
        unordered_map<int, int> ab_map; // sum,次数
        unordered_map<int, int> cd_map; // sum,次数

        for (int i = 0; i < nums1.size(); ++i)
        {
            for (int j = 0; j < nums2.size(); ++j)
            {
                int sum = 0;
                sum = nums1[i] + nums2[j];
                ab_map[sum]++;
            }  
        }

        for (int i = 0; i < nums3.size(); ++i)
        {
            for (int j = 0; j < nums4.size(); ++j)
            {
                int sum = 0;
                sum = nums3[i] + nums4[j];
                cd_map[sum]++;
            }
        }
        int count = 0;
        for(auto&&i:ab_map){
            auto it = cd_map.find(-i.first);
            if(it!=cd_map.end())
            {
                count += cd_map[-i.first] * i.second;
            }
        }
        return count;
    }
};
// @lc code=end
