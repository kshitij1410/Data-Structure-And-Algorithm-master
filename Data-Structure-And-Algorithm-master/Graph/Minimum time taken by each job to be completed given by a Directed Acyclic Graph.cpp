//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    vector<int> minimumTime(int n, vector<vector<int>> &edges, int m)
    {
        // adj and indegree
        vector<int> adj[n + 1];
        vector<int> indegree(n + 1, 0);
        vector<int> ans(n + 1, 0);

        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;
        for (int i = 1; i <= n; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
                ans[i] = 1;
            }
        }

        while (!q.empty())
        {
            int top = q.front();
            q.pop();

            for (auto nbr : adj[top])
            {
                indegree[nbr]--;

                if (indegree[nbr] == 0)
                {
                    q.push(nbr);
                    ans[nbr] = ans[top] + 1;
                }
            }
        }
        ans.erase(ans.begin());
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int m;
        cin >> m;
        vector<vector<int>> edges(m, vector<int>(2));
        for (int i = 0; i < m; i++)
            cin >> edges[i][0] >> edges[i][1];
        Solution s;
        vector<int> ans = s.minimumTime(n, edges, m);
        for (auto j : ans)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends