class Solution
{
public:
    int minSteps(string s, string t)
    {
        vector<int> v1(26, 0);
        vector<int> v2(26, 0);
        int ans = 0;
        for (int i = 0; i < s.length(); i++)
        {
            v1[s[i] - '0' - 49]++;
            v2[t[i] - '0' - 49]++;
        }
        for (int i = 0; i < 26; i++)
        {
            ans += abs(v1[i] - v2[i]);
        }
        if (ans % 2)
        {
            return ans / 2 + 1;
        }
        return ans / 2;
    }
};