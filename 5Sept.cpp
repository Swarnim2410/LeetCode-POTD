public:
    // Function to return the adjacency list for each vertex.
    vector<vector<int>> printGraph(int v, vector<pair<int,int>>edges) 
    {
        vector<int>adj[v];
        for(auto it : edges)
        {
            adj[it.first].push_back(it.second);
            adj[it.second].push_back(it.first);
        }
        vector<vector<int>>ans;
        for(int i=0;i<v;i++)
        {
            vector<int>temp = adj[i];
            ans.push_back(temp);
        }
        return ans;
        // Code here
    }
