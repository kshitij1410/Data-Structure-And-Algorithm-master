//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find if the given edge is a bridge in graph.
    void solve(vector<int> adj[], int c, int d, int node, int parent, vector<int> &low, vector<int> &vis, vector<int> &tim, int &timer, vector<vector<int>> &ans)
    {
        vis[node] = 1;
        low[node] = tim[node] = timer++;

        for (auto nbr : adj[node])
        {
            if (nbr == parent)
                continue;
            if (vis[nbr] == 0)
            {
                solve(adj, c, d, nbr, node, low, vis, tim, timer, ans);

                // minimize the low
                low[node] = min(low[node], low[nbr]);

                // check bridge
                if (low[nbr] > tim[node])
                {
                    vector<int> res;
                    res.push_back(node);
                    res.push_back(nbr);
                    ans.push_back(res);
                }
            }
            else
            {
                // back edge
                low[node] = min(tim[nbr], low[node]);
            }
        }
    }

    int isBridge(int v, vector<int> adj[], int c, int d)
    {
        vector<int> low(v, 0);
        vector<int> vis(v, 0);
        vector<int> tim(v);
        int timer = 0;
        int parent = -1;
        vector<vector<int>> ans;

        for (int i = 0; i < v; i++)
        {
            if (vis[i] == 0)
                solve(adj, c, d, i, parent, low, vis, tim, timer, ans);
        }

        bool res = 0;
        
        // check for bridge condition
        for (int i = 0; i < ans.size(); i++)
        {
            int x = ans[i][0];
            int y = ans[i][1];
            // cout<<"["<<x<<","<<y<<"]"<<"\n";
            if ((x == c and y == d) or (x == d and y == c))
            {
                res = 1;
                break;
            }
        }

        return res;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i = 0;
        while (i++ < E)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int c, d;
        cin >> c >> d;

        Solution obj;
        cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}

// } Driver Code Ends