class Solution
{
public:
    bool isVowel(char c)
    {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            return true;
        if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
            return true;
        return false;
    }
    bool halvesAreAlike(string s)
    {
        int c = 0;
        for (int i = 0; i < s.length() / 2; i++)
        {
            if (isVowel(s[i]))
            {
                c++;
            }
        }
        for (int i = s.length() / 2; i < s.length(); i++)
        {
            if (isVowel(s[i]))
            {
                c--;
            }
        }
        return c == 0;
    }
};