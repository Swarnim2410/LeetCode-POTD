class Solution
{
public:
    int countCharacters(vector<string> &w, string c)
    {
        sort(c.begin(), c.end());
        int ans = 0;
        for (int i = 0; i < w.size(); i++)
        {
            string s = w[i];
            sort(s.begin(), s.end());
            w[i] = s;
        }
        for (int i = 0; i < w.size(); i++)
        {
            string s = w[i];
            int j = 0;
            int k = 0;
            while (j < s.size() && k < c.size())
            {
                if (s[j] == c[k])
                {
                    j++;
                    k++;
                }
                else
                {
                    k++;
                }
            }
            if (j == s.length())
            {
                ans += s.length();
            }
        }
        return ans;
    }
};