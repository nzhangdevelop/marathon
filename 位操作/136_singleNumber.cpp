class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        // 利用异或的特性，两个相同的数字，异或的结果为0；
        // 一个数和0异或的结果为它自己。
        int single = 0;
        for (auto i : nums)
        {
            single ^= i;
        }
        return single;
    }
};