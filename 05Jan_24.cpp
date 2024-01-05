class Solution
{
public:
    // MEMOIZATION...

    /*int solve(int i,int prev,vector<int>& nums,vector<vector<int>>&dp)
    {
        if(i == nums.size())
        {
            return 0;
        }
        if(dp[i][prev+1]!=-1)
        {
            return dp[i][prev+1];
        }
        int notpick = solve(i+1,prev,nums,dp);
        int pick = 0;
        if(prev == -1 || nums[i] > nums[prev])
        {
            pick = 1 + solve(i+1,i,nums,dp);
        }
        return dp[i][prev+1] = max(pick,notpick);
    }
    int lengthOfLIS(vector<int>& nums)
    {
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return solve(0,-1,nums,dp);
    }*/

    // TABULATION...

    /*int lengthOfLIS(vector<int>& nums)
    {
        int n = nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int i=n-1;i>=0;i--)
        {
            //j i.e. previous index starts from i-1 because it cannot go beyond it..
            for(int j=i-1;j>=-1;j--)
            {
                //same code as memoization...
                //just in second parameter, we do a +1..
                //here we did a +1 -> int notpick = dp[i+1][j+1];
                int pick = 0;
                if(j==-1 || nums[i]>nums[j])
                {
                    //here we did a +1 -> pick = 1 + dp[i+1][i+1];
                }
                dp[i][j+1] = max(pick,notpick);
            }
        }
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=n;j++)
            {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        return dp[0][0];
    }*/

    // USING BINARY SEARCH...

    // TC - O(NlogN)
    // SC - O(N)

    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans;
        // push first element in the ans array(ans array will be always sorted)...
        ans.push_back(nums[0]);
        for (int i = 1; i < n; i++)
        {
            // if current element is greater than largest element of
            // ans, push current element at the last..
            if (nums[i] > ans.back())
            {
                ans.push_back(nums[i]);
            }
            else
            {
                // this lower bound will return same index if current element is found
                // in ans, else it return index of element which is first
                // greater than current element (which we exactly need)...
                int idx = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
                ans[idx] = nums[i];
            }
        }
        return ans.size();
    }
};