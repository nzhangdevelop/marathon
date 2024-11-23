class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> v;
        map<int, int> m;
        m.insert({nums[0], 0});
        for (int i = 1; i < nums.size(); i++)
        {
            if (m.count(target - nums[i]) > 0)
            {
                v.push_back(m[target - nums[i]]);
                v.push_back(i);
            }
            m.insert({nums[i], i});
        }
        return v;
    }
};