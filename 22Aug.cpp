class Solution {
public:
    string convertToTitle(int col) 
    {
        string s = "";
        while(col>0)
        {
            int rem = col%26;
            col=col/26;
            if(rem==0)
            {
                s.push_back('Z');
                col--;
            }
            else
            {
                int newval = rem + 64;
                char ch = (char)newval;
                s.push_back(ch);
            }
        }
        reverse(s.begin(),s.end());
        return s;
    }
};