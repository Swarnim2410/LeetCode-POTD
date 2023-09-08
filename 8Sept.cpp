class Solution {
public:
    vector<vector<int>> generate(int n) 
    {
        vector<vector<int>>ans;
        vector<int>v(1,1);
        ans.push_back(v);
        if(n==1)
        {
            return ans;
        }
        v.resize(2,1);
        ans.push_back(v);
        int idx = 1;
        for(int i=3;i<=n;i++)
        {
            vector<int>curr(i,1);
            for(int x=0;x<v.size()-1;x++)
            {
                curr[idx] = v[x] + v[x+1];
                idx++;
            }
            idx = 1;
            ans.push_back(curr);
            v = curr;
        }
        return ans;

    }
};