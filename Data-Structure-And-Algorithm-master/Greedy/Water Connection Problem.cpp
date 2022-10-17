//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int diam = INT_MAX;
    int dfs(vector<pair<int, int>> adj[], int node)
    {
        for (auto nbr : adj[node])
        {
            diam = min(nbr.second, diam);
            return dfs(adj, nbr.first);
        }

        return node;
    }

    vector<vector<int>> solve(int n, int p, vector<int> a, vector<int> b, vector<int> d)
    {
        vector<int> indegree(n + 1, 0);
        vector<pair<int, int>> adj[n + 1];
        vector<vector<int>> res;

        for (int i = 0; i < p; i++)
        {
            adj[a[i]].push_back({b[i], d[i]});
            indegree[b[i]]++;
        }

        queue<int> q;

        for (int i = 1; i <= n; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        while (!q.empty())
        {
            int top = q.front();
            q.pop();
            diam = INT_MAX;
            int last = top;
            if (adj[top].size() > 0)
            {
                last = dfs(adj, top);
                res.push_back({top, last, diam});
            }
        }

        return res;
    }
};

//{ Driver Code Starts.
int main()
{
    int t, n, p;
    cin >> t;
    while (t--)
    {
        cin >> n >> p;
        vector<int> a(p), b(p), d(p);
        for (int i = 0; i < p; i++)
        {
            cin >> a[i] >> b[i] >> d[i];
        }
        Solution obj;
        vector<vector<int>> answer = obj.solve(n, p, a, b, d);
        cout << answer.size() << endl;
        for (auto i : answer)
        {
            cout << i[0] << " " << i[1] << " " << i[2] << endl;
        }
    }
    return 0;
}
// } Driver Code Ends