class Solution
{
public:
    long long largestPerimeter(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<long long> pre(n, 0);
        pre[0] = nums[0];
        for (int i = 1; i < n; i++)
        {
            pre[i] = pre[i - 1] + nums[i];
        }
        long long sum = nums[0] + nums[1];
        int f = 0;
        long long maxi = 0;
        for (int i = 2; i < n; i++)
        {
            sum += nums[i];
            if (nums[i] < pre[i - 1])
            {
                f = 1;
                maxi = max(maxi, sum);
            }
        }
        if (f == 0)
        {
            return -1;
        }
        return maxi;
    }
};