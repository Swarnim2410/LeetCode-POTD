class Solution
{
public:
    vector<int> findDiagonalOrder(vector<vector<int>> &nums)
    {
        int m = nums.size();
        map<int, vector<int>> mp;
        vector<int> ans;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < nums[i].size(); j++)
            {
                mp[i + j].push_back(nums[i][j]);
            }
        }
        for (auto it : mp)
        {
            vector<int> temp = it.second;
            int n = temp.size();
            for (int i = n - 1; i >= 0; i--)
            {
                ans.push_back(temp[i]);
            }
        }
        return ans;
    }
};