/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 * 2025-1-2：一刷
 */
#include <vector>
#include <string>
using namespace std;

// @lc code=start
class Solution
{
private:
    vector<string> res;
    string path;

    vector<string> getStringList(string digits)
    {
        vector<string> stringList;
        for (auto digit : digits)
        {
            switch (digit)
            {
            case '2':
                stringList.push_back("abc");
                break;
            case '3':
                stringList.push_back("def");
                break;
            case '4':
                stringList.push_back("ghi");
                break;
            case '5':
                stringList.push_back("jkl");
                break;
            case '6':
                stringList.push_back("mno");
                break;
            case '7':
                stringList.push_back("pqrs");
                break;
            case '8':
                stringList.push_back("tuv");
                break;
            case '9':
                stringList.push_back("wxyz");
                break;
            default:
                break;
            }
        }
        return stringList;
    }

    void backtrack(vector<string> stringList, int index)
    {
        if (path.size() == stringList.size())
        {
            res.push_back(path);
            return;
        }

        for (int i = 0; i < stringList[index].size(); ++i)
        {
            path.push_back(stringList[index][i]);
            backtrack(stringList, index + 1);
            path.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits)
    {
        res.clear();
        if (digits.empty())
            return res;
        vector<string> stringList = getStringList(digits);
        backtrack(stringList, 0);
        return res;
    }
};
// @lc code=end
