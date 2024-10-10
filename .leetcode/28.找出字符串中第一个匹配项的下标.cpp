/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 找出字符串中第一个匹配项的下标（KMP）
 * 一刷:2024-10-9:不会写,看了题解也不是很懂,基本上是背下来的
 */
#include <string>
#include <vector>
using namespace std;

// @lc code=start
class Solution
{
public:
    // next数组的每一位其实就是保存了每个子串的最大相等前后缀的长度,求它只跟模式串有关
    void getNext(int *next, string &s)
    {
        int j = -1;
        next[0] = j;
        for (int i = 1; i < s.size(); ++i)
        {
            while (j >= 0 && s[j + 1] != s[i]) //j>=0使得j+1==0,即j在初始位置时,与后缀不匹配也没事
                j = next[j];
            if (s[j + 1] == s[i])
                ++j;
            next[i] = j;
        }
    }

    int strStr(string haystack, string needle)
    {
        if (needle.size() == 0)
            return 0;

        int j = -1;
        int *next = new int[needle.size()]();

        getNext(next, needle);

        for (int i = 0; i < haystack.size(); ++i)
        {
            while (needle[j + 1] != haystack[i] && j >= 0)
                j = next[j];

            if (needle[j + 1] == haystack[i])
                ++j;
            
            if (j == (needle.size() - 1))
                return (i - needle.size() + 1);
        }
        return -1;
    }
};
// @lc code=end
