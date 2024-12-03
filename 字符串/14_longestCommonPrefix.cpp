class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        // strs[0][0], strs[1][0], strs[2][0];
        // strs[0][1], strs[1][1], strs[2][1];
        // strs[0][2], strs[1][2], strs[2][2];

        // 纵向比较，依次比较所有字符串的第i个字符。
        // 为什么可以这么写？因为最长公共前缀不会大于任意一个字符串。
        int length = strs[0].size();
        for (int i = 0; i < length; i++) // 第i个字符
        {
            for (int j = 1; j < strs.size(); j++)
            {
                // 语法问题：如果前面的条件成立，还会不会执行后面的表达式。
                if (i == strs[j].size() || strs[j][i] != strs[0][i])
                {
                    return strs[0].substr(0, i);
                }
            }
        }
        return strs[0];
    }
};