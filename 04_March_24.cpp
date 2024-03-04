class Solution
{
public:
    int bagOfTokensScore(vector<int> &t, int p)
    {
        sort(t.begin(), t.end());
        int n = t.size();
        int i = 0;
        int j = n - 1;
        int c = 0;
        while (i <= j)
        {
            if (p >= t[i])
            {
                c++;
                p -= t[i];
                i++;
            }
            else
            {
                if (c == 0)
                {
                    break;
                }
                else
                {
                    if (i != j)
                    {
                        c--;
                        p += t[j];
                    }
                    j--;
                }
            }
        }
        return c;
    }
};