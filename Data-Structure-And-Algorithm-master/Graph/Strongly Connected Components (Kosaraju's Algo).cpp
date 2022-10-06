//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    void dfs(vector<int> &vis, vector<int> adj[], int node, stack<int> &st)
    {
        vis[node] = 1;

        for (auto nbr : adj[node])
        {
            if (vis[nbr] == 0)
            {
                dfs(vis, adj, nbr, st);
            }
        }

        st.push(node);
    }

    void dfs1(vector<int> &vis, vector<int> adj[], int node)
    {
        vis[node] = 1;

        for (auto nbr : adj[node])
        {
            if (vis[nbr] == 0)
            {
                dfs1(vis, adj, nbr);
            }
        }
    }

    int kosaraju(int v, vector<int> adj[])
    {
        // topo sort
        stack<int> st;
        vector<int> vis(v, 0);
        for (int i = 0; i < v; i++)
        {
            if (vis[i] == 0)
            {
                dfs(vis, adj, i, st);
            }
        }

        // memset(vis,0,sizeof(vis));
        fill(vis.begin(), vis.end(), 0);

        // transpose
        vector<int> transpose[v];

        for (int i = 0; i < v; i++)
        {
            for (auto x : adj[i])
            {
                transpose[x].push_back(i);
            }
        }

        // count component;
        int count = 0;

        while (!st.empty())
        {
            int top = st.top();
            st.pop();

            if (vis[top] == 0)
            {
                count++;
                dfs1(vis, transpose, top);
            }
        }

        return count;
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

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends