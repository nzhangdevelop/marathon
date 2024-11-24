class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        // 例子3：paper, title
        // 很多人可能对例3有疑问，其实他这里的映射是不同单词的相同字母可以有不同的映射
        unordered_map<char, char> s2t;
        unordered_map<char, char> t2s;
        for (int i = 0; i < s.length(); ++i)
        {
            char x = s[i];
            char y = t[i];
            // 这句话是关键。
            // 什么情况是不同构的呢？
            // s字符串中存在[x : y]的一个映射，并且当前x为key映射的value不等于y，即存在x对多字符。
            // 同理判断字符串t。
            if ((s2t.count(x) && s2t[x] != y) || (t2s.count(y) && t2s[y] != x))
            {
                return false;
            }
            s2t[x] = y;
            t2s[y] = x;
        }
        return true;
    }
};