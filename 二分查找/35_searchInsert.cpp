class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int n = nums.size();
        int l = 0;
        int r = n - 1;
        int pos = n;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            // target > nums[mid], 继续往右边找；
            // 肯能不存在等于target的值，返回n，即数组的最右端。
            if (target > nums[mid])
            {
                l = mid + 1;
            }
            // target < nums[mid],继续往左边找；
            // 可能不存在等于target的值，返回0；
            else if (target < nums[mid])
            {
                r = mid - 1;
                // 找到第一个大于等于target的下标。
                pos = mid;
            }
            // target == nums[mid],找到target；
            else
            {
                return mid;
            }
        }
        return pos;
    }
};