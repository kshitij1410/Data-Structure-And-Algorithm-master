#include <bits/stdc++.h>

vector<int> shortestPath(vector<pair<int, int>> edges, int n, int m, int s, int t)
{

    // adj
    vector<int> adj[n + 1];

    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // bfs
    queue<int> q;
    vector<int> vis(n + 1, 0);
    q.push(s);
    vector<int> parent(n + 1, -1);
    vis[s] = 1;

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (auto nbr : adj[node])
        {
            if (!vis[nbr])
            {
                parent[nbr] = node;
                vis[nbr] = 1;
                q.push(nbr);
            }
        }
    }

    vector<int> ans;
    ans.push_back(t);
    int temp = t;

    while (temp != s)
    {
        temp = parent[temp];
        ans.push_back(temp);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
