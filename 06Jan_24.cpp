class Solution
{
public:
    int func(int idx, vector<vector<int>> &x, vector<int> &st, int n, vector<int> &dp)
    {
        if (idx >= n)
        {
            return 0;
        }
        if (dp[idx] != -1)
        {
            return dp[idx];
        }
        // searching next start time after current end time..
        int a = lower_bound(st.begin(), st.end(), x[idx][1]) - st.begin();
        int pick = x[idx][2] + func(a, x, st, n, dp);
        int notpick = func(idx + 1, x, st, n, dp);
        return dp[idx] = max(pick, notpick);
    }
    int jobScheduling(vector<int> &st, vector<int> &et, vector<int> &pr)
    {
        int n = st.size();
        vector<vector<int>> x;
        for (int i = 0; i < n; i++)
        {
            x.push_back({st[i], et[i], pr[i]});
        }
        vector<int> dp(n + 1, -1);
        sort(x.begin(), x.end());
        sort(st.begin(), st.end());
        return func(0, x, st, n, dp);
    }
};