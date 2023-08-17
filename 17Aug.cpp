class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) 
    {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]==0)
                {
                    vis[i][j] = 1;
                    q.push({i,j});
                }
            }
        }
        while(q.size())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int row=-1;row<=1;row++)
            {
                for(int col=-1;col<=1;col++)
                {
                    if(abs(row)+abs(col)==2)
                    {
                        continue;
                    }
                    int i = x + row;
                    int j = y + col;
                    if(i>=0 && j>=0 && i<m && j<n)
                    {
                        if(vis[i][j]==0)
                        {
                            mat[i][j] = 1 + mat[x][y];
                            vis[i][j] = 1;
                            q.push({i,j});
                        }
                    }
                }
            }
        }
        return mat;    
    }
};