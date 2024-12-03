// 中等难度。
// 是否beat 100%：否
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        // 如果intervals里区间的数量为空，返回intervals
        if (intervals.size() == 0)
        {
            return intervals;
        }
        // 按左端点升序给intervals排序。
        sort(intervals.begin(), intervals.end());
        // 遍历数组，将排序后的intervals中的区间逐个与merged最后一个
        // 区间比较，如果当前intervals[i]的左端点大于merged.back()
        // 的右端点，那么intervals[i]作为独立区间（不被合并）push到
        // merged。
        vector<vector<int>> merged;
        for (int i = 0; i < intervals.size(); i++)
        {
            int L = intervals[i][0];
            int R = intervals[i][1];
            // if (L > merged.back()[1] || !merged.size())
            // ！！注意这里的语法问题，要把merged的判空操作放在前面。
            // 否则，由于程序的顺序执行，merged首次是空，会发生执行错误。
            if (!merged.size() || L > merged.back()[1])
            {
                merged.push_back({L, R});
            }
            else
            {
                // 将右端较大的作为区间右端点。
                merged.back()[1] = max(merged.back()[1], R);
            }
        }
        return merged;
    }
};