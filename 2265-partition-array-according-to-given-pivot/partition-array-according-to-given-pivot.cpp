class Solution
{
public:
    vector<int> pivotArray(vector<int> &nums, int pivot)
    {
        int low = 0;
        int same = 0;
        int high;
        for (auto n : nums)
        {
            if (n < pivot)
            {
                ++low;
            }
            else if (n == pivot)
            {
                ++same;
            }
        }
        vector<int> res(nums.size());
        high = same + low;
        same = low;
        low = 0;
        for (auto n : nums)
        {
            if (n < pivot)
            {
                res[low++] = n;
            }
            else if (n == pivot)
            {
                res[same++] = n;
            }
            else
            {
                res[high++] = n;
            }
        }
        return res;
    }
};