class Solution {
public:
    string reverseWords(string s) 
    {
        vector<string>v;
        string s1;
        string s2;
        int a =1;
        for(int i=0;i<s.length();i++)
        {
            if(s[i] == ' ')
            {
                reverse(s1.begin(),s1.end());
                v.push_back(s1);
                while(a)
                {
                    v.push_back(" ");
                    a--;
                }
                s1 = ' ';
            }
            else
            {
                s1 = s1 + s[i];
            }

        }
        reverse(s1.begin(),s1.end());
        v.push_back(s1);
        for(int i=0;i<v.size();i++)
        {
            s2 = s2 + v[i];

        }
        int size = s2.length();
        if(s2[size-1]==' ')

        {s2.pop_back();}
        return s2;
    }
};