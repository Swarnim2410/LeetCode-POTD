class Solution
{
public:
    vector<vector<int>> transpose(vector<vector<int>> &ma)
    {
        int m = ma.size();
        int n = ma[0].size();
        vector<vector<int>> ans;
        for (int j = 0; j < n; j++)
        {
            vector<int> v;
            for (int i = 0; i < m; i++)
            {
                v.push_back(ma[i][j]);
            }
            ans.push_back(v);
        }
        return ans;
    }
};