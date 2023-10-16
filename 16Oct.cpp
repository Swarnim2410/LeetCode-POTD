class Solution
{
public:
    vector<int> getRow(int n)
    {
        if (n == 0)
        {
            vector<int> v(1, 1);
            return v;
        }
        if (n == 1)
        {
            vector<int> v(2, 1);
            return v;
        }
        vector<int> prev(2, 1);
        int idx = 1;
        for (int i = 2; i <= n; i++)
        {
            vector<int> curr(i + 1, 1);
            for (int x = 0; x < prev.size() - 1; x++)
            {
                curr[idx] = prev[x] + prev[x + 1];
                idx++;
            }
            idx = 1;
            prev = curr;
        }
        return prev;
    }
};