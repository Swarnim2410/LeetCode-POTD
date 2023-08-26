class Solution {
public:

    int func(int i,int prev,vector<vector<int>>&dp,vector<vector<int>>& pairs,int n)
    {
        if(i==n)
        {
            return 0;
        }
        if(dp[i][prev+1]!=-1)
        {
            return dp[i][prev+1];
        }
        int pick=0;
        int notpick=0;
        if(prev==-1)
        {
            pick=1+func(i+1,i,dp,pairs,n);
            notpick=func(i+1,-1,dp,pairs,n);
        }
        else
        {
            notpick=func(i+1,prev,dp,pairs,n);
            if(pairs[i][0]>pairs[prev][1])
            {
                pick=1+func(i+1,i,dp,pairs,n);
            }
        }
        return dp[i][prev+1]=max(pick,notpick);
    }
    int findLongestChain(vector<vector<int>>& pairs) 
    {
        int n = pairs.size();
        sort(pairs.begin(),pairs.end());
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return func(0,-1,dp,pairs,n);
    }
};