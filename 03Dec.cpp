class Solution
{
public:
    int minTimeToVisitAllPoints(vector<vector<int>> &p)
    {
        int ans = 0;
        for (int i = 0; i < p.size() - 1; i++)
        {
            int a = max(abs(p[i][0] - p[i + 1][0]), abs(p[i][1] - p[i + 1][1]));
            ans += a;
        }
        return ans;
    }
};