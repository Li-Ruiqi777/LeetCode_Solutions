/*
 * @lc app=leetcode.cn id=844 lang=cpp
 *
 * [844] 比较含退格的字符串
 */

#include <string>
#include <iostream>
using namespace std;

// @lc code=start
class Solution
{
public:
    bool backspaceCompare(string s, string t)
    {
        int t1 = this->getResult(s);
        int t2 = this->getResult(t);
        std::cout << std::endl;
        std::cout << s << std::endl;
        std::cout << t << std::endl;

        if (s.size() - t1 != t.size() - t2)
            return false;

        for (int i = 0; i < s.size() - t1; i++)
        {
            if (s[i] != t[i])
                return false;
        }
        return true;
    }

private:
    int getResult(string &str)
    {
        int times = 0;
        int slowIdx = 0;
        for (int fastIdx = 1; fastIdx < str.size(); fastIdx++)
        {
            if (str[fastIdx] != '#')
            {
                ++slowIdx;
                if (str[fastIdx != '#'])
                    str[slowIdx] = str[fastIdx];
            }
            else
            {
                if (slowIdx >= 0)
                {
                    --slowIdx;
                    ++times;
                }
            }
        }
        return times;
    }
};
// @lc code=end

int main()
{
    Solution s;
    string s1 = "ab##";
    string s2 = "c#d#";
    bool res = s.backspaceCompare(s1, s2);

    return 0;
}
