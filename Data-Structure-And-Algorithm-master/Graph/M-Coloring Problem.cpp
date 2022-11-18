//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    bool isSafe(bool graph[101][101], vector<int> color, int m, int n, int col, int node)
    {
        for (int i = 0; i < n; i++)
        {
            if (i != node and graph[node][i] == 1 and color[i] == col)
                return false;
        }

        // if the adj list is present then check the nbr
        return true;
    }

    bool solve(bool graph[101][101], int m, int n, int node, vector<int> &color)
    {
        if (node == n)
            return true;

        for (int col = 1; col <= m; col++)
        {
            if (isSafe(graph, color, m, n, col, node))
            {
                color[node] = col;
                if (solve(graph, m, n, node + 1, color))
                    return true;

                // backtrack
                color[node] = 0;
            }
        }

        return false;
    }

    bool graphColoring(bool graph[101][101], int m, int n)
    {
        vector<int> color(n, 0);

        return solve(graph, m, n, 0, color);
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++)
        {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++)
        {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends