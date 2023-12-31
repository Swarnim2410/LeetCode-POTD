----------------------SOLUTION 1 USING BITMASKING ----------------------------

class Solution {
public:
    int dfs(int curr,vector<vector<int>>&dist,int mask,vector<vector<int>>&dp,int n)
    {
        if(mask == 0)
        {
            return 0;
        }
        if(dp[curr][mask]!=-1)
        {
            return dp[curr][mask];
        }
        int ans = 1e9;
        for(int i=0;i<n;i++)
        {
            int vis = (1<<i) & mask;
            if(vis)
            {
                int path = dfs(i,dist,mask^(1<<i),dp,n) + dist[curr][i];
                ans = min(ans,path);
            }
        }
        return dp[curr][mask] = ans;
    }
    int shortestPathLength(vector<vector<int>>&graph) 
    {
        int n = graph.size();
        int maxsize = pow(2,n);
        vector<vector<int>>dist(n,vector<int>(n,1e9));
        for(int i=0;i<n;i++)
        {
            dist[i][i] = 0;
            for(int j=0;j<graph[i].size();j++)
            {
                dist[i][graph[i][j]] = 1;
            }
        }
        for(int k=0;k<n;k++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(dist[i][j]>dist[i][k] + dist[k][j])
                    {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
        int ans = 1e9;
        vector<vector<int>>dp(n,vector<int>(maxsize,-1));
        for(int i=0;i<n;i++)
        {
            int mask = (1<<n) - 1;
            int val = dfs(i,dist,mask^(1<<i),dp,n);
            ans = min(ans,val);
        }   
        return ans;
    }
};



----------------------------------SOLUTION 2 USING STRING -------------------------------------------


class Solution {
public:
    int dfs(int curr,vector<vector<int>>&dist,string &temp,string finalans,vector<vector<int>>&dp,int n)
    {
        if(temp==finalans)
        {
            return 0;
        }
        int a=0;
        for (int i=0;i<n;i++) 
        {
            a+=(temp[i]-'0')<<i;
        }
        //cout << a << endl;
        if(dp[curr][a]!=-1)
        {
            return dp[curr][a];
        }
        int ans = 1e9;
        for(int i=0;i<n;i++)
        {
            if(temp[i]=='0')
            {
                temp[i] = '1';
                int path = dfs(i,dist,temp,finalans,dp,n) + dist[curr][i];
                temp[i] = '0';
                ans = min(ans,path);
            }
        }
        return dp[curr][a] = ans;
    }
    int shortestPathLength(vector<vector<int>>&graph) 
    {
        int n = graph.size();
        int maxsize = pow(2,n);
        vector<vector<int>>dist(n,vector<int>(n,1e9));
        for(int i=0;i<n;i++)
        {
            dist[i][i] = 0;
            for(int j=0;j<graph[i].size();j++)
            {
                dist[i][graph[i][j]] = 1;
            }
        }
        for(int k=0;k<n;k++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(dist[i][j]>dist[i][k] + dist[k][j])
                    {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=0;j<n;j++)
        //     {
        //         cout << dist[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        int ans = 1e9;
        string s(n,'0');
        string finalans(n,'1');
        vector<vector<int>>dp(n,vector<int>(maxsize,-1));
        for(int i=0;i<n;i++)
        {
            string temp = s;
            temp[i] = '1';
            int val = dfs(i,dist,temp,finalans,dp,n);
            ans = min(ans,val);
        }   
        return ans;
    }
};