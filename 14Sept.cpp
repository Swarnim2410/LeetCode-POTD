class Solution {
public:
    string mini = "";
    bool dfs(string currstr,unordered_map<string,vector<string>>&mp,map<pair<string,string>,int>&m,vector<string>&curr,string &temp,int n,vector<string>&finalans)
    {
        if(curr.size()==n+1)
        {
            if(mini == "" || temp<mini)
            {
                mini = temp;
                finalans = curr;
            }
            return true;
        }
        for(auto it : mp[currstr])
        {
            if(m[{currstr,it}])
            {
                curr.push_back(it);
                m[{currstr,it}]--;
                temp += it;
                bool o = dfs(it,mp,m,curr,temp,n,finalans);
                if(o)
                {
                    return true;
                }
                curr.pop_back();
                temp.pop_back();
                temp.pop_back();
                temp.pop_back();
                m[{currstr,it}]++;
            }
        }
        return false;
    }
    vector<string> findItinerary(vector<vector<string>>&t) 
    {
        int n = t.size();
        unordered_map<string,vector<string>>mp;
        map<pair<string,string>,int>m;
        vector<string>ans;
        for(int i=0;i<n;i++)
        {
            mp[t[i][0]].push_back(t[i][1]);
            m[{t[i][0],t[i][1]}]++;
        }
        for(auto it : mp)
        {
            vector<string>temp = it.second;
            sort(temp.begin(),temp.end());
            mp[it.first] = temp;
        }
        string temp = "JFK";
        vector<string>curr;
        curr.push_back("JFK");
        vector<string>finalans;
        bool x = dfs("JFK",mp,m,curr,temp,n,finalans);
        return finalans;
    }
};