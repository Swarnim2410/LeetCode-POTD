class Solution
{
public:
    int maxLengthBetweenEqualCharacters(string s)
    {
        vector<int> v(26, -1);
        int maxi = -1;
        for (int i = 0; i < s.length(); i++)
        {
            if (v[s[i] - '0' - 49] == -1)
            {
                v[s[i] - '0' - 49] = i;
            }
            else
            {
                maxi = max(maxi, i - v[s[i] - '0' - 49] - 1);
            }
        }
        return maxi;
    }
};