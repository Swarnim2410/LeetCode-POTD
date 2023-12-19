class Solution
{
public:
    vector<vector<int>> imageSmoother(vector<vector<int>> &img)
    {
        int m = img.size();
        int n = img[0].size();
        vector<vector<int>> ans(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                double ans1 = 0;
                double cnt = 0;
                for (int a = -1; a <= 1; a++)
                {
                    for (int b = -1; b <= 1; b++)
                    {
                        int nrow = i + a;
                        int ncol = j + b;
                        if (nrow >= 0 && ncol >= 0 && nrow < m && ncol < n)
                        {
                            ans1 += img[nrow][ncol];
                            cnt++;
                        }
                    }
                }
                ans1 /= cnt;
                ans[i][j] = ans1;
            }
        }
        return ans;
    }
};