/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 * 一刷:2024-10-2
 */

#include <vector>
#include <unordered_map>
using namespace std;

// @lc code=start
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int,int> hash_map; //num,index
        vector<int> res;
        for(int i=0;i<nums.size();++i){
            int key = target - nums[i];
            auto it = hash_map.find(key);
            if(it != hash_map.end())
            {
                res.push_back(i);
                res.push_back(it->second);
                return res;
            }

            hash_map[nums[i]] = i;
        }
        return res;
    }
};
// @lc code=end
