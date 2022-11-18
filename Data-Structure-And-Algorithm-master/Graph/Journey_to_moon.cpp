#include <bits/stdc++.h>
#define int long long int
using namespace std;

void dfs(int node, vector<int> adj[], int n, vector<int> &vis, int &counter)
{
    vis[node] = 1;
    counter++;

    for (auto nbr : adj[node])
    {
        if (vis[nbr] == 0)
            dfs(nbr, adj, n, vis, counter);
    }
}

int solve(vector<int> adj[], int n)
{

    vector<int> vis(n, 0);
    int totalPoss = (n * (n - 1)) / 2;

    for (int i = 0; i < n; i++)
    {

        if (vis[i] == 0)
        {
            int counter = 0;
            dfs(i, adj, n, vis, counter);

            totalPoss = totalPoss - (counter * (counter - 1)) / 2;
        }
    }

    return totalPoss;
}

int32_t main()
{
    int n, p;
    cin >> n >> p;
    vector<int> adj[n];
    for (int i = 0; i < p; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int ans = solve(adj, n);
    cout << ans;
    return 0;
}
