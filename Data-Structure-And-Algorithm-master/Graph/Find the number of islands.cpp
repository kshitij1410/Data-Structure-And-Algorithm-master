#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    
    void dfs(vector<vector<int>> &vis, vector<vector<char>> &grid, int i, int j, int n, int m)
    {
        queue<pair<int, int>> q;
        q.push({i, j});
        vis[i][j] = 1;

        while (!q.empty())
        {
            int ix = q.front().first;
            int iy = q.front().second;
            q.pop();

            for (int irow = -1; irow <= 1; irow++)
            {
                for (int ico = -1; ico <= 1; ico++)
                {
                    int xxi = ix + irow;
                    int xxj = iy + ico;

                    if (xxi >= 0 and xxi < n and xxj >= 0 and xxj < m and vis[xxi][xxj] == 0 and grid[xxi][xxj] == '1')
                    {
                        q.push({xxi, xxj});
                        vis[xxi][xxj] = 1;
                    }
                }
            }
        }
    }

    int numIslands(vector<vector<char>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (vis[i][j] == 0 and grid[i][j] == '1')
                {
                    dfs(vis, grid, i, j, n, m);
                    ans++;
                }
            }
        }

        return ans;
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
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
