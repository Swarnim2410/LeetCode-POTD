class Solution
{
public:
    int mod = (int)1e9 + 7;
    int func(int n, int remsum, int k, vector<vector<int>> &dp)
    {
        if (n == 1)
        {
            if (remsum <= k)
            {
                return 1;
            }
            return 0;
        }
        if (dp[n][remsum] != -1)
        {
            return dp[n][remsum];
        }
        int ans = 0;
        for (int val = 1; val <= k; val++)
        {
            if (val < remsum)
            {
                ans = (ans + func(n - 1, remsum - val, k, dp)) % mod;
            }
        }
        return dp[n][remsum] = ans;
    }
    int numRollsToTarget(int n, int k, int target)
    {
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
        return func(n, target, k, dp) % mod;
    }
};