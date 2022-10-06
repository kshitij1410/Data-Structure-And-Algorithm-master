//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    void solve(vector<int> adj[], int node, int parent, vector<int> &low, vector<int> &vis, vector<int> &tim, int &timer, vector<int> &ans)
    {
        vis[node] = 1;
        low[node] = tim[node] = timer++;
        int child = 0;

        for (auto nbr : adj[node])
        {
            if (nbr == parent)
                continue;
            if (vis[nbr] == 0)
            {

                solve(adj, nbr, node, low, vis, tim, timer, ans);

                // minimize the low
                low[node] = min(low[node], low[nbr]);

                // check articuation point
                if (low[nbr] >= tim[node] and parent != -1)
                {
                    ans[node] = 1;
                }
                child++;
            }
            else
            {
                // back edge
                low[node] = min(tim[nbr], low[node]);
            }
        }

        if (parent == -1 and child > 1)
        {
            ans[node] = 1;
        }
    }
    vector<int> articulationPoints(int v, vector<int> adj[])
    {

        vector<int> low(v, 0);
        vector<int> vis(v, 0);
        vector<int> tim(v);
        int timer = 0;
        int parent = -1;
        vector<int> ans(v, 0);

        for (int i = 0; i < v; i++)
        {
            if (vis[i] == 0)
                solve(adj, i, parent, low, vis, tim, timer, ans);
        }

        vector<int> res;
        for (int i = 0; i < ans.size(); i++)
        {
            if (ans[i] == 1)
                res.push_back(i);
        }

        if (res.size() == 0)
            return {-1};

        return res;
    }
};

//{ Driver Code Starts.

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        vector<int> ans = obj.articulationPoints(V, adj);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends