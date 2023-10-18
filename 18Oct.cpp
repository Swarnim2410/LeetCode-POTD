class Solution
{
public:
    int minimumTime(int n, vector<vector<int>> &r, vector<int> &t)
    {
        vector<int> indegree(n + 1, 0);
        vector<int> adj[n + 1];
        for (int i = 0; i < r.size(); i++)
        {
            adj[r[i][0]].push_back(r[i][1]);
        }
        for (int i = 1; i <= n; i++)
        {
            for (auto it : adj[i])
            {
                indegree[it]++;
            }
        }
        unordered_map<int, int> mp;
        queue<pair<int, int>> q;
        for (int i = 1; i <= n; i++)
        {
            if (indegree[i] == 0)
            {
                q.push({t[i - 1], i});
            }
        }
        int ans = 0;
        while (q.size())
        {
            int val = q.front().first;
            int node = q.front().second;
            ans = max(ans, val);
            q.pop();
            for (auto it : adj[node])
            {
                mp[it] = max(mp[it], val);
                indegree[it]--;
                if (indegree[it] == 0)
                {
                    q.push({mp[it] + t[it - 1], it});
                }
            }
        }
        return ans;
    }
};