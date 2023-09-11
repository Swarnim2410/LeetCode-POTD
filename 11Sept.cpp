class Solution
{
public:
    vector<vector<int>> groupThePeople(vector<int> &groupSizes)
    {
        int n = groupSizes.size();
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++)
        {
            mp[groupSizes[i]].push_back(i);
        }
        vector<vector<int>> ans;
        for (auto it : mp)
        {
            int a = it.first;
            vector<int> temp = it.second;
            vector<int> x;
            for (int i = 0; i < temp.size(); i++)
            {
                x.push_back(temp[i]);
                if (x.size() == a)
                {
                    ans.push_back(x);
                    x.clear();
                }
            }
        }
        return ans;
    }
};