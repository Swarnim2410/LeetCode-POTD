class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int x = *max_element(nums.begin(), nums.end());
        int f = 0;
        int m = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (x == nums[i] && f == 0)
            {
                f = 1;
            }
            else if (x == nums[i] && f == 1)
            {
                m = x;
                break;
            }
            else
            {
                m = max(m, nums[i]);
            }
        }
        return (x - 1) * (m - 1);
    }
};