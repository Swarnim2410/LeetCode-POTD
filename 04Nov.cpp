class Solution
{
public:
    int getLastMoment(int n, vector<int> &l, vector<int> &r)
    {
        sort(r.begin(), r.end());
        int x = -1e8;
        if (r.size())
        {
            x = n - r[0];
        }
        sort(l.begin(), l.end(), greater<int>());
        int y = -1e8;
        if (l.size())
        {
            y = l[0];
        }
        if (x == -1e8 && y == -1e8)
        {
            return 0;
        }
        return max(x, y);
    }
};