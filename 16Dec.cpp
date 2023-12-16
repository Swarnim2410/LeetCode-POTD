class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        vector<int> v;
        map<char, int> m1;
        map<char, int> m2;
        // count frequency of all characters in m1
        for (auto v : s)
        {
            m1[v]++;
        }
        for (auto v : t)
        {
            m2[v]++;
        }
        return m1 == m2;
    }
};