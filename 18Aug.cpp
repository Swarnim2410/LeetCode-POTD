class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) 
    {
        vector<int>deg(n,0);
        map<pair<int,int>,bool>mp;
        for(int i=0;i<roads.size();i++)
        {
            deg[roads[i][0]]++;
            deg[roads[i][1]]++;
            mp[{roads[i][0],roads[i][1]}] = 1;
            mp[{roads[i][1],roads[i][0]}] = 1;
        }
        int maxi = 0;
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                int val = deg[i] + deg[j];
                if(val<=maxi)
                {
                    continue;
                }
                if(mp[{i,j}]==1)
                {
                    val--;
                }
                maxi = max(maxi,val);
            }
        }
        return maxi;
    }
};