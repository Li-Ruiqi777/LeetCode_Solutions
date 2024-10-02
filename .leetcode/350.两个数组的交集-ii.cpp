/*
 * @lc app=leetcode.cn id=350 lang=cpp
 *
 * [350] 两个数组的交集 II
 * 一刷:2024-10-2
 */
#include <vector>
#include <unordered_map>
using namespace std;
// @lc code=start
class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int, int> hash_map1;
        for (auto &&i : nums1)
        {
            hash_map1[i]++;
        }

        unordered_map<int, int> hash_map2;
        for (auto &&i : nums2)
        {
            if(hash_map1.find(i)!=0)
                hash_map2[i]++;
        }

        vector<int> result;
        for(auto &&i:hash_map2){
            if(hash_map1[i.first] < i.second)
                i.second = hash_map1[i.first];
            for(int k=0;k<i.second;++k)
                result.push_back(i.first);
        }
        return result;
    }
};
// @lc code=end
