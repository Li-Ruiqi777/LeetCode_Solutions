// 一刷：2024-7-17，没写出来。可以先思考不用二分法的基础思路：从数组最左边开始向右遍历，找到一个点(P)，左边的点比他小、右边的点也比他小.
//  本题其实就是使用二分法来找P(认为区间的中点为P),而不是朴素的遍历法。如果P<P+1，则波峰在右边，移动区间的左边界；如果P>P+1，则认为
//  波峰在P的左边，移动区间的右边界

class Solution
{
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param nums int整型vector
     * @return int整型
     */
    int findPeakElement(vector<int> &nums)
    {
        // write code here
        int left = 0;
        int right = nums.size() - 1;

        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] < nums[mid + 1])
                left = mid + 1;
            else
                right = mid;
        }
        return right;
    }
};