class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        // 遍历一遍数组，计算每次到当天为止的最小股票价格和最大利润。
        int maxProfit = 0, cost = INT_MAX;
        for (int price : prices)
        {
            cost = min(cost, price);
            maxProfit = max(maxProfit, price - cost);
        }
        return maxProfit;
    }
};