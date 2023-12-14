class Solution
{
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> zeroes(m, vector<int>(n, 0));
        vector<vector<int>> ones(m, vector<int>(n, 0));
        vector<vector<int>> ans(m, vector<int>(n, 0));
        int sum = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                sum += grid[i][j];
            }
            for (int j = 0; j < n; j++)
            {
                zeroes[i][j] += n - sum;
                ones[i][j] += sum;
            }
            sum = 0;
        }
        sum = 0;
        for (int j = 0; j < n; j++)
        {
            for (int i = 0; i < m; i++)
            {
                sum += grid[i][j];
            }
            for (int i = 0; i < m; i++)
            {
                zeroes[i][j] += m - sum;
                ones[i][j] += sum;
            }
            sum = 0;
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                ans[i][j] = ones[i][j] - zeroes[i][j];
            }
        }
        return ans;
    }
};