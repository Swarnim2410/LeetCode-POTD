class Solution
{
public:
    vector<int> findArray(vector<int> &p)
    {
        vector<int> ans;
        ans.push_back(p[0]);
        int x = p[0];
        for (int i = 1; i < p.size(); i++)
        {
            int y = x ^ p[i];
            ans.push_back(y);
            x = x ^ y;
        }
        return ans;
    }
};