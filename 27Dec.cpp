class Solution
{
public:
    int minCost(string clr, vector<int> &nt)
    {
        int n = clr.size();
        if (n == 1)
        {
            return 0;
        }
        int time = 0;
        int maxi = 0;
        int c = 0;
        int fans = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (clr[i] == clr[i + 1])
            {
                time += nt[i];
                maxi = max(maxi, nt[i]);
                c++;
            }
            else
            {
                if (c)
                {
                    time += nt[i];
                    maxi = max(maxi, nt[i]);
                    fans += (time - maxi);
                    c = 0;
                    time = 0;
                    maxi = 0;
                }
            }
        }
        if (c)
        {
            time += nt[n - 1];
            maxi = max(maxi, nt[n - 1]);
            fans += (time - maxi);
        }
        return fans;
    }
};