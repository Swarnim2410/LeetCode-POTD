class Solution
{
public:
    int minPairSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int maxi = INT_MIN;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            int a = nums[i] + nums[nums.size() - i - 1];
            maxi = max(a, maxi);
        }
        return maxi;
    }
};