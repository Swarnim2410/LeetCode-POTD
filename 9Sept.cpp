class Solution {
public:

    //MEMOIZATION CODE -->

    /*int func(vector<int>&nums,int remsum,int n,vector<int>&dp)
    {
        if(remsum==0)
        {
            return 1;
        }
        if(dp[remsum]!=-1)
        {
            return dp[remsum];
        }
        int cnt = 0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]<=remsum)
            {
                cnt += func(nums,remsum-nums[i],n,dp);
            }
            else
            {
                break;
            }
        }
        return dp[remsum] = cnt;
    }*/

    //TABULATION CODE -->
    
    int combinationSum4(vector<int>& nums, int t) 
    {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<double>dp(t+1,1);
        for(int i=1;i<=t;i++)
        {
            double cnt = 0;
            for(int j=0;j<n;j++)
            {
                if(nums[j]<=i)
                {
                    cnt += dp[i-nums[j]];
                }
                else
                {
                    break;
                }
            }
            dp[i] = cnt;
        }
        return (int)dp[t];
    }
};