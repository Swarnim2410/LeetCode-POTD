class Solution {
public:

    int spanningTree(vector<vector<int>>mp[],int n)
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>vis(n+1,0);
        pq.push({0,0});
        int sum=0;
        while(pq.size())
        {
            int wt = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if(vis[node]==1)
            {
                continue;
            }
            vis[node] = 1;
            sum+=wt;
            for(auto it : mp[node])
            {
                if(vis[it[0]]==0)
                {
                    pq.push({it[1],it[0]});
                }
            }
        }
        return sum;
    }
    int minCostConnectPoints(vector<vector<int>>&p) 
    {
        int n = p.size();
        int firstval = p[0][0];
        int secondval = p[0][1];
        vector<vector<int>>mp[n];
        for(int i=0;i<n;i++)
        {
            int x1 = p[i][0];
            int y1 = p[i][1];
            for(int j=i+1;j<n;j++)
            {
                int x2 = p[j][0];
                int y2 = p[j][1];
                int dis = abs(x1-x2) + abs(y1-y2);
                vector<int>temp;
                temp.push_back(j);
                temp.push_back(dis);
                mp[i].push_back(temp);
                temp[0] = i;
                mp[j].push_back(temp);
            }
        }
        return spanningTree(mp,n);
    }
};