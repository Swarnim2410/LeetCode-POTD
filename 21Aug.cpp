class Solution {
public:
    bool repeatedSubstringPattern(string s) 
    {
        int n = s.length();
        string temp = "";
        for(int i=0;i<s.length()-1;i++)
        {
            int f=0;
            temp.push_back(s[i]);
            int len = temp.length();
            if(n%len)
            {
                continue;
            }
            int x = i+1;
            while(x<n)
            {
                string r = s.substr(x,len);
                if(r!=temp)
                {
                    f=1;
                    break;
                }
                x=x+len;
            }
            if(f==0)
            {
                return true;
            }
        } 
        return false;   
    }
};