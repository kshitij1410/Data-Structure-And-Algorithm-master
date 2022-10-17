/*
Problem Statement: Given a weighted directed graph with negative edge weights with n nodes and m edges.
Nodes are labeled from 0 to n-1, the task is to find the shortest distance from the source node to all
other nodes. Output “-1” if there exists a negative edge weight cycle in the graph.
Note: edges[i] is defined as u, v and weight.

Examples:

Example 1:

Input:
Edges : [[0,1,5],[1,5,-3],[1,2,-2],[2,4,3],[3,2,6],[3,4,-2],[5,3,1]]

Output: [0,5,3,3,1,2]
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int isNegativeWeightCycle(int n, vector<vector<int>> edges)
    {

        // loop throught n-1 times
        vector<int> dist(n, INT_MAX);
        int src = 0;
        dist[src] = 0;

        for (int i = 0; i < n - 1; i++)
        {
            // traverse on each edge
            for (int j = 0; j < edges.size(); j++)
            {
                int u = edges[j][0];
                int v = edges[j][1];
                int wt = edges[j][2];

                if (dist[u] != INT_MAX and ((dist[u] + wt) < dist[v]))
                    dist[v] = dist[u] + wt;
            }
        }

        bool flag = 0;
        // check for negative cycle

        for (int j = 0; j < edges.size(); j++)
        {
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];

            if (dist[u] != INT_MAX and ((dist[u] + wt) < dist[v]))
            {
                dist[v] = dist[u] + wt;
                flag = 1;
            }
        }

        return flag;
    }
};

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; i++)
        {
            int x, y, z;
            cin >> x >> y >> z;
            edges.push_back({x, y, z});
        }
        Solution obj;
        int ans = obj.isNegativeWeightCycle(n, edges);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends