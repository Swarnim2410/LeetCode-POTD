class Solution
{
public:
    vector<string> buildArray(vector<int> &t, int n)
    {
        int size = t.size();
        vector<string> ans;
        int i = 0;
        int x = 1;
        while (i < size)
        {
            ans.push_back("Push");
            if (x == t[i])
            {
                i++;
            }
            else
            {
                ans.push_back("Pop");
            }
            x++;
        }
        return ans;
    }
};