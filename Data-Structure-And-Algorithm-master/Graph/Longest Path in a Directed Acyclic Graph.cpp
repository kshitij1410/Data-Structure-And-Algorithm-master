
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:

    // it give tle TC-O(V(V+E))
    vector<int> maximumDistance(vector<vector<int>> edges, int n, int e, int src)
    {
        vector<int> ans(n, INT_MIN);
        ans[src] = 0;
        vector<pair<int, int>> adj[n];
        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            adj[u].push_back({v, w});
        }

        queue<pair<int, int>> q;
        q.push({0, src});

        while (!q.empty())
        {
            int node = q.front().second;
            int dis = q.front().first;
            q.pop();
            for (auto nbr : adj[node])
            {
                int nbrNode = nbr.first;
                int nbrDis = nbr.second;
                if (ans[node] + nbrDis > ans[nbrNode])
                {
                    ans[nbrNode] = nbrDis + ans[node];
                    q.push({ans[nbrNode], nbrNode});
                }
            }
        }

        return ans;
    }
};

// optimize solution is TC-O(V+E)

class Solution
{
public:
    vector<int> order;

    void topo(int src, vector<int> &vis, vector<pair<int, int>> adj[])
    {
        vis[src] = 1;
        for (auto nbr : adj[src])
        {
            if (vis[nbr.first] == 0)
            {
                topo(nbr.first, vis, adj);
            }
        }
        order.push_back(src);
    }

    vector<int> maximumDistance(vector<vector<int>> edges, int n, int e, int src)
    {
        vector<int> vis(n, 0);
        vector<int> ans(n, INT_MIN);
        ans[src] = 0;
        vector<pair<int, int>> adj[n];
        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            adj[u].push_back({v, w});
        }
        //topo sort order 
        for (int i = 0; i < n; i++)
        {
            if (vis[i] == 0)
            {
                topo(i, vis, adj);
            }
        }
         
        for (int i = n - 1; i >= 0; i--)
        {
            if (ans[order[i]] != INT_MIN)
            {
                for (auto nbr : adj[order[i]])
                {
                    int nbrNode = nbr.first;
                    int nbrDis = nbr.second;
                    if (nbrDis + ans[order[i]] > ans[nbrNode])
                        ans[nbrNode] = nbrDis + ans[order[i]];
                }
            }
        }

        return ans;
    }
};

int main()
{

    int t;
    cin >> t;
    while (t--)
    {

        int v, e;
        cin >> v >> e;

        int src;
        cin >> src;
        vector<vector<int>> edges(e, vector<int>(3));
        for (auto &j : edges)
            cin >> j[0] >> j[1] >> j[2];

        Solution s;
        vector<int> ans = s.maximumDistance(edges, v, e, src);
        for (auto j : ans)
        {
            if (j == INT_MIN)
                cout << "INF ";
            else
                cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
