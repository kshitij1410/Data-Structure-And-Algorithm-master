class Solution
{
public:
    void dfs(vector<int> &vis, vector<int> adj[], int src)
    {
        vis[src] = 1;

        for (auto nbr : adj[src])
        {
            if (vis[nbr] == 0)
            {
                dfs(vis, adj, nbr);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>> &connections)
    {
        // unordered_map<int,vector<int>>adj;
        vector<int> adj[n];
        int edges = 0;
        int component = 0;
        for (int i = 0; i < connections.size(); i++)
        {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
            edges += 1;
        }
        vector<int> vis(n, 0);

        for (int i = 0; i < n; i++)
        {
            if (vis[i] == 0)
            {
                component += 1;
                dfs(vis, adj, i);
            }
        }
        int req = n - 1;
        if (edges < req)
            return -1;
        return component - 1;
    }
};