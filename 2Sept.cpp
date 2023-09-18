class Solution {
public:
    /*int func(int idx,string s, vector<string>& dict,int n,int m,vector<int>&dp,unordered_map<string,int>&mp)
    {
        if(idx == n)
        {
            return 0;
        }
        if(dp[idx]!=-1)
        {
            return dp[idx];
        }
        int notpick = 1 + func(idx+1,s,dict,n,m,dp,mp);
        int pick = INT_MAX;
        string temp = "";
        for(int j=idx;j<n;j++)
        {
            temp.push_back(s[j]);
            if(mp[temp])
            {
                pick = min(pick,func(j+1,s,dict,n,m,dp,mp));
            }
        }
        return dp[idx] = min(pick,notpick);
    }*/
    int minExtraChar(string s, vector<string>& dict) 
    {
        int n = s.length();
        int m = dict.size();
        unordered_map<string,int>mp;
        for(int i=0;i<m;i++)
        {
            mp[dict[i]]++;
        }
        vector<int>dp(n+2,0);
        //return func(0,s,dict,n,m,dp,mp);
        for(int idx=n-1;idx>=0;idx--)
        {
            int notpick = 1 + dp[idx+1];
            int pick = INT_MAX;
            string temp = "";
            for(int j=idx;j<n;j++)
            {
                temp.push_back(s[j]);
                if(mp[temp])
                {
                    pick = min(pick,dp[j+1]);
                }
            }
            dp[idx] = min(pick,notpick);  
        } 
        return dp[0];
    }
};