#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int res = 0;
    void solve(vector<vector<char>> &mat, string target, int i, int j, int r, int c, int idx)
    {
        if (i >= 0 and i < r and j >= 0 and j < c and target[idx] == mat[i][j])
        {
            char temp = mat[i][j];
            if (idx + 1 == target.size())
                res++;
            mat[i][j] = '0';

            solve(mat, target, i - 1, j, r, c, idx + 1);
            solve(mat, target, i, j - 1, r, c, idx + 1);
            solve(mat, target, i, j + 1, r, c, idx + 1);
            solve(mat, target, i + 1, j, r, c, idx + 1);

            mat[i][j] = temp;
        }
        else
            return;
    }
    int findOccurrence(vector<vector<char>> &mat, string target)
    {
        int r = mat.size();
        int c = mat[0].size();
        int ans = 0;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                res = 0;
                solve(mat, target, i, j, r, c, 0);
                ans += res;
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
        int R, C;
        cin >> R >> C;
        vector<vector<char>> mat(R);
        for (int i = 0; i < R; i++)
        {
            mat[i].resize(C);
            for (int j = 0; j < C; j++)
                cin >> mat[i][j];
        }
        string target;
        cin >> target;
        Solution obj;
        cout << obj.findOccurrence(mat, target) << endl;
    }
}

// } Driver Code Ends