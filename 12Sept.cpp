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
        int lastmiss = x;
        int cnt=0;
        for(auto it : ans)
        {
            int x = it.second;
            if(lastmiss == 0)
            {
                cnt += abs(x-lastmiss);
                continue;
            }
            if(x<=lastmiss)
            {
                lastmiss = x-1;
            }
            else
            {
                cnt += abs(x-lastmiss);
                lastmiss--;
            }
        }
        return cnt;
    }
};