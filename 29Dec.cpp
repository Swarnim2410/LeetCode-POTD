class Solution
{
public:
    int func(int idx, int n, int d, vector<int> &arr, vector<vector<vector<int>>> &dp, int m)
    {
        if (d == 1)
        {
            int maxi = m;
            for (int i = idx; i < n; i++)
            {
                maxi = max(maxi, arr[i]);
            }
            return maxi;
        }
        if (idx == n)
        {
            return 1e9;
        }
        if (dp[idx][d][m] != -1)
        {
            return dp[idx][d][m];
        }
        int x = 1e9, y = 1e9;
        x = func(idx + 1, n, d, arr, dp, max(m, arr[idx]));
        y = m + func(idx + 1, n, d - 1, arr, dp, arr[idx]);
        return dp[idx][d][m] = min(x, y);
    }
    int minDifficulty(vector<int> &arr, int d)
    {
        int n = arr.size();
        if (n < d)
        {
            return -1;
        }
        if (n + d == 2)
        {
            return arr[0];
        }
        int maxi = 0;
        for (int i = 0; i < n; i++)
        {
            maxi = max(maxi, arr[i]);
        }
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(d + 1, vector<int>(maxi + 1, -1)));
        return func(1, n, d, arr, dp, arr[0]);
    }
};