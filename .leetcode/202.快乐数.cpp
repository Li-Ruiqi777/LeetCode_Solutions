/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 * 一刷:2024-10-2
 */
#include <unordered_set>
#include <math.h>
// @lc code=start
class Solution {
public:
    int getSum(int num){
        int sum = 0;
        while(num){
            sum +=(num%10) * (num%10);
            num/=10;
        }
        return sum;
    }

    bool isHappy(int n) {
        std::unordered_set<int> set;
        while(1){
            int sum = getSum(n);
            if(sum==1)
                break;
            if(set.find(sum)!=set.end())
                return false;
            set.insert(sum);
            n = sum;

        }
        return true;
    }
};
// @lc code=end

