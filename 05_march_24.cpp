class Solution
{
public:
    int minimumLength(string s)
    {
        int n = s.length();
        int i = 0;
        int j = n - 1;
        char prev = 'd';
        while (i <= j)
        {
            if (i == j)
            {
                if (prev != s[i])
                {
                    return 1;
                }
            }
            if (prev == 'd')
            {
                if (s[i] == s[j])
                {
                    prev = s[i];
                    i++;
                    j--;
                }
                else
                {
                    return j - i + 1;
                }
            }
            else
            {
                if (s[i] == s[j])
                {
                    prev = s[i];
                    i++;
                    j--;
                }
                else
                {
                    if (s[i] == prev)
                    {
                        i++;
                    }
                    else if (s[j] == prev)
                    {
                        j--;
                    }
                    else
                    {
                        // cout << i << " " << j << endl;
                        return j - i + 1;
                    }
                }
            }
        }
        return 0;
    }
};