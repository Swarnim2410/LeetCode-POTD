class Solution
{
public:
    int maxScore(string s)
    {
        int n = s.length();
        int z = 0, o = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '0')
            {
                z++;
            }
            else
            {
                o++;
            }
        }
        int maxi = 0;
        int a = 0, b = 0;
        for (int i = 0; i < n - 1; i++)
        {
            if (s[i] == '0')
            {
                a++;
            }
            else
            {
                b++;
            }
            maxi = max(maxi, a + o - b);
        }
        return maxi;
    }
};