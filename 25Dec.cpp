class Solution
{
public:
    int numDecodings(string s)
    {
        int n = s.length();
        if (s[0] == '0')
        {
            return 0;
        }
        int sin = 1;
        int dou = 0;
        int ways = 1;
        for (int i = 1; i < n; i++)
        {
            if (s[i] == '0')
            {
                if (s[i - 1] != '1' && s[i - 1] != '2')
                {
                    ways = 0;
                    break;
                }
                else
                {
                    dou = sin;
                    sin = 0;
                    ways = sin + dou;
                }
            }
            else
            {
                int nsin = ways;
                if (sin == 0)
                {
                    dou = 0;
                }
                else
                {
                    // int nsin = ways;
                    int t = (s[i - 1] - '0') * 10 + (s[i] - '0');
                    //cout << t << endl;
                    if (t >= 10 && t <= 26)
                    {
                        dou = sin;
                    }
                    else
                    {
                        dou = 0;
                    }
                }
                sin = nsin;
                ways = sin + dou;
            }
        }
        return ways;
    }
};