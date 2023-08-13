class Solution {
public:

    //MEMOIZATION -->

    /*bool func(int idx,vector<int>&dp,vector<int>&nums,int n)
    {
        if(idx==0)
        {
            return false;
        }
        if(idx<0)
        {
            return true;
        }
        if(dp[idx]!=-1)
        {
            return dp[idx];
        }
        bool two = 0;
        bool three = 0;
        bool threeinc = 0;
        if(idx>=1 && nums[idx]==nums[idx-1])
        {
            two = func(idx-2,dp,nums,n);
        }
        if(idx>=2 && nums[idx] == nums[idx-1] && nums[idx-1] == nums[idx-2])
        {
            three = func(idx-3,dp,nums,n);
        }
        if(idx>=2 &&  nums[idx]==nums[idx-1]+1 && nums[idx-1] == nums[idx-2]+1)
        {
            threeinc = func(idx-3,dp,nums,n);
        }
        return dp[idx] =  two || three || threeinc;
    }
    bool validPartition(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int>dp(n,-1);
        return func(n-1,dp,nums,n);
    }*/

    bool validPartition(vector<int>& nums) 
    {
        int n = nums.size();
        vector<bool>dp(n,0);
        for(int idx=1;idx<n;idx++)
        {
            bool two = 0;
            bool three = 0;
            bool threeinc = 0;
            if(idx>=1 && nums[idx]==nums[idx-1])
            {
                if(idx-2<0)
                {
                    two = 1;
                }
                else
                {
                    two = dp[idx-2];
                }
            }
            if(idx>=2 && nums[idx] == nums[idx-1] && nums[idx-1] == nums[idx-2])
            {
                if(idx-3<0)
                {
                    three = 1;
                }
                else
                {
                    three = dp[idx-3];
                }
            }
            if(idx>=2 &&  nums[idx]==nums[idx-1]+1 && nums[idx-1] == nums[idx-2]+1)
            {
                if(idx-3<0)
                {
                    threeinc = 1;
                }
                else
                {
                    threeinc = dp[idx-3];
                }
            }
            dp[idx] =  two || three || threeinc;
        }
        return dp[n-1];
    }
};