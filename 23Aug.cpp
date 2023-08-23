class Solution {
public:

    static bool cmp(pair<char,int>& a,pair<char,int>& b)
    {
        return a.second > b.second;
    }
    vector<pair<char,int>> sort(map<char,int>&mp)
    {
        vector<pair<char,int>>A;
        for (auto&it :mp) 
        {
            A.push_back(it);
        }
        ::sort(A.begin(), A.end(), cmp);
        return A;
    }
    string reorganizeString(string s) 
    {
        string val = "";
        for(int i=0;i<s.length();i++)
        {
            val.push_back('A');
        }
        int cnt = s.length();
        map<char,int>mp;
        int count = 0;
        char ch = 'A';
        int n = s.length();
        for(int i=0;i<n;i++)
        {
            mp[s[i]]++;
            if(count==0)
            {
                ch = s[i];
                count = 1;
            }
            else if(ch==s[i])
            {
                count++;
            }
            else
            {
                count--;
            }
        }  
        vector<pair<char,int>>ans = sort(mp);
        int count2 = 0;
        for(int i=0;i<n;i++)
        {
            if(s[i]==ch)
            {
                count2++;
            }
        }
        if(n%2)
        {
            if(count2>n/2+1)
            {
                return "";
            }
            else
            {
                int i=0;
                int idx=0;
                while(cnt)
                {
                    if(i==n+1)
                    {
                        i=1;
                    }
                    if(ans[idx].second==0)
                    {
                        idx++;
                    }
                    val[i]=ans[idx].first;
                    ans[idx].second--;
                    i=i+2;
                    cnt--;
                }
                return val;
            }
        }
        else
        {
            if(count2>=n/2+1)
            {
                return "";
            }
            else
            {
                int i=0;
                int idx=0;
                while(cnt)
                {
                    if(i==n)
                    {
                        i=1;
                    }
                    if(ans[idx].second==0)
                    {
                        idx++;
                    }
                    val[i]=ans[idx].first;
                    ans[idx].second--;
                    i=i+2;
                    cnt--;
                }
                return val;
            }
        }
        return "";  
    }
};