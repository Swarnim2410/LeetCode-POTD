class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) 
    {
        vector<int>ans;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        int m = mat.size();
        int n = mat[0].size();
        int i=0;
        while(i<m)
        {
            int c=0;
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]==0)
                {
                    break;
                }
                else
                {
                    c++;
                }
            }
            pq.push({c,i});
            i++;
        }
        while(k--)
        {
            pair<int,int>p = pq.top();
            pq.pop();
            ans.push_back(p.second);
        }
        return ans;
    }
};