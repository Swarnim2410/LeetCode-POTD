class Solution {
public:

    /*bool func(int i,int k,vector<int>arr,vector<vector<int>>&dp)
    {
        if(i==arr.size()-1)
        {
            return true;
        }
        if(i>=arr.size())
        {
            return false;
        }
        if(dp[i][k]!=-1)
        {
            return dp[i][k];
        }
        bool first = false;
        if(k>1)
        {
            first = (i+k-1<arr.size()) && (arr[i+k-1]==1) && (func(i+k-1,k-1,arr,dp));
        }
        bool second = (i+k<arr.size()) && (arr[i+k]==1) && (func(i+k,k,arr,dp));
        bool third = (i+k+1<arr.size()) && (arr[i+k+1]==1) && (func(i+k+1,k+1,arr,dp));
        return dp[i][k] = first || second || third;
    }*/
    
    bool found(vector<int> &stones,int curr)
    {
        return binary_search(stones.begin(),stones.end(),curr);
    }
    bool func(long long curr,long long jumps,map<pair<long long,long long>,bool>&dp,int maxi,vector<int>&stones)
    {
        if(curr == maxi)
        {
            return true;
        }
        if(dp.find({curr,jumps})!=dp.end()) 
        {
            return dp[{curr,jumps}];
        }
        int left = jumps - 1;
        int center = jumps;
        int right = jumps + 1;
        bool a = false;
        bool b = false;
        bool c = false;
        if(jumps == 1)
        {
            if(curr+center <= maxi && found(stones,curr+center))
            {
                b = func(curr+center,center,dp,maxi,stones);
            }
            if(curr+right <= maxi && found(stones,curr+right))
            {
                c = func(curr+right,right,dp,maxi,stones);
            }
        }
        else
        {
            if(curr+left<=maxi && found(stones,curr+left))
            {
                a = func(curr+left,left,dp,maxi,stones);
            }
            if(curr+center <= maxi && found(stones,curr+center))
            {
                b = func(curr+center,center,dp,maxi,stones);
            }
            if(curr+right <= maxi && found(stones,curr+right))
            {
                c = func(curr+right,right,dp,maxi,stones);
            }
        }
        return dp[{curr,jumps}] = a || b || c;
    }
    bool canCross(vector<int>& stones) 
    {
        int n = stones.size();
        int maxi = stones[n-1];
        map<pair<long long,long long>,bool>dp;
        if(stones[1]!=1)
        {
            return false;
        }
        return func(1,1,dp,maxi,stones);
    }
};