class Solution
{
public:
    int mod = 1e9 + 7;
    int func(int idx, int s, int n, vector<vector<long long>> &dp, int x)
    {
        if (x == s)
        {
            if (idx == 0)
            {
                return 1;
            }
            return 0;
        }
        if (dp[idx][x] != -1)
        {
            return dp[idx][x];
        }
        long long left = 0, curr = 0, right = 0;
        if (idx > 0)
        {
            left = func(idx - 1, s, n, dp, x + 1) % mod;
        }
        curr = func(idx, s, n, dp, x + 1) % mod;
        if (idx < n - 1)
        {
            right = func(idx + 1, s, n, dp, x + 1) % mod;
        }
        return dp[idx][x] = (left + right + curr) % mod;
    }
    int numWays(int s, int n)
    {
        int mini = min(n, s);
        vector<vector<long long>> dp(mini + 1, vector<long long>(s + 1, -1));
        return func(0, s, n, dp, 0);
    }
};