class Solution {
public:
    char findTheDifference(string s, string t) 
    {
        t+=s;
        int x=0;
        for(int i=0;i<t.length();i++)
        {
            x^=t[i];
        }
        return x;
    }
};