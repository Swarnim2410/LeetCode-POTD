class Solution {
public:

    static bool cmp(pair<char, int> &a, pair<char, int> &b)
    {
        return a.second > b.second;
    }
    vector<pair<char, int>> sort(map<char, int> &mp)
    {
        vector<pair<char, int>> A;
        for (auto &it : mp)
        {
            A.push_back(it);
        }
        ::sort(A.begin(), A.end(), cmp);
        return A;
    }
    int minDeletions(string s) 
    {
        map<char,int>mp;
        for(auto it : s)
        {
            mp[it]++;
        }
        vector<pair<char, int>> ans = sort(mp);
        int x;
        for(auto it : ans)
        {
            x = it.second;
            break;
        }
        vector<int>vis(x+1,0);
        int cnt=0;
        for(auto it : ans)
        {
            int x = it.second;
            if(vis[x]==0)
            {
                vis[x]=1;
                continue;
            }
            while(x)
            {
                cnt++;
                x--;
                if(vis[x]==0)
                {
                    vis[x]=1;
                    break;
                }
            }
        }
        return cnt;
    }
};