#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void shortest_distance(vector<vector<int>> &mat)
    {

        int n = mat.size();

        for (int k = 0; k < mat.size(); k++)
        {
            for (int u = 0; u < n; u++)
            {
                for (int v = 0; v < n; v++)
                {
                    if (mat[u][k] == -1 or mat[k][v] == -1)
                        continue;
                    int new_dist = mat[u][k] + mat[k][v];
                    if (mat[u][v] == -1 or mat[u][v] > new_dist)
                        mat[u][v] = new_dist;
                }
            }
        }
    }
};

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<vector<int>> matrix(n, vector<int>(n, -1));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> matrix[i][j];
            }
        }
        Solution obj;
        obj.shortest_distance(matrix);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << matrix[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
// } Driver Code Ends