class Solution
{
public:
    string destCity(vector<vector<string>> &paths)
    {
        map<string, int> mp;
        for (int i = 0; i < paths.size(); i++)
        {
            mp[paths[i][0]] = -1;
            if (mp[paths[i][1]] != -1)
            {
                mp[paths[i][1]] = 1;
            }
        }
        for (auto it : mp)
        {
            if (it.second == 1)
            {
                return it.first;
            }
        }
        return "";
    }
};