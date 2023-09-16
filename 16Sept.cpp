class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) 
    {
        //min priority queue of <int,<int,int>> i.e. <dis,<i,j>>
        priority_queue<pair<int, pair<int, int>>,
        vector<pair<int, pair<int, int>>>,
        greater<pair<int, pair<int, int>>>>pq;
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        dist[0][0] = 0;
        pq.push({0,{0,0}});
        while(pq.size())
        {
            int currdiff = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            pq.pop();
            if(i==n-1 && j==m-1)
            {
                return currdiff;
            }
            for(int row=-1;row<=1;row++)
            {
                for(int col=-1;col<=1;col++)
                {
                    if(abs(row)+abs(col)==2)
                    {
                        continue;
                    }
                    int nrow = i+row;
                    int ncol = j+col;
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m)
                    {
                        int eff = abs(heights[nrow][ncol] - heights[i][j]);
                        int neweff = max(eff,currdiff);
                        if(neweff < dist[nrow][ncol])
                        {
                            dist[nrow][ncol] = neweff;
                            pq.push({neweff,{nrow,ncol}});
                        }
                    }
                }
            }
        }
        return 0;
    }
};