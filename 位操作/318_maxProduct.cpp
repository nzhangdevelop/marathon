class Solution
{
public:
    int maxProduct(vector<string> &words)
    {
        // 这题要用到位运算和unordered_map（哈希表）；
        // key: mask, value: 最大长度。
        // 用一个整数的二进制形式，记录words中的字符串中的字符是否在
        // 26个字母中出现（题目仅包含小写字母）。并作为key。
        unordered_map<int, int> catches;
        int max_value = 0;
        for (const string &s : words)
        {
            int mask = 0;
            int s_len = s.length();
            // mask中存了哪些字符有在s中出现，1 表示存在。
            for (char c : s)
            {
                mask |= 1 << (c - 'a');
            }
            catches[mask] = max(catches[mask], s_len);
            for (auto [key, value] : catches)
            {
                // 如果下面的条件为真，则两个字符串没有相同的字母。
                if ((key & mask) == 0)
                {
                    max_value = max(value * s_len, max_value);
                }
            }
        }
        return max_value;
    }
};