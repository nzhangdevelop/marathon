class Solution
{
public:
    int findContentChildren(vector<int> &g, vector<int> &s)
    {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int nChildren = g.size();
        int nCookies = s.size();
        int child = 0, cookie = 0;
        while (child < nChildren && cookie < nCookies)
        {
            if (g[child] <= s[cookie])
            {
                child++;
            }
            cookie++;
        }
        return child;
    }
};