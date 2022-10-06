//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to find out minimum steps Knight needs to reach target position.
    int minStepToReachTarget(vector<int> &KnightPos, vector<int> &TargetPos, int N)
    {
        int x1 = KnightPos[0] - 1;
        int y1 = KnightPos[1] - 1;
        int tx = TargetPos[0] - 1;
        int ty = TargetPos[1] - 1;
        int n = N;

        if (x1 == tx and y1 == ty)
            return 0;

        queue<pair<int, int>> q;
        q.push({x1, y1});
        int dx[] = {-1, 1, -1, 1, -2, 2, -2, 2};
        int dy[] = {2, 2, -2, -2, 1, 1, -1, -1};
        int steps = 0;
        vector<vector<int>> vis(n, vector<int>(n, 0));
        vis[x1][y1] = 1;

        while (!q.empty())
        {

            int size = q.size();
            steps++;
            while (size != 0)
            {
                int tempx = q.front().first;
                int tempy = q.front().second;
                q.pop();

                for (int i = 0; i < 8; i++)
                {
                    int xx = tempx + dx[i];
                    int yy = tempy + dy[i];

                    if (xx == tx and yy == ty)
                        return steps;

                    if (xx >= 0 and xx < n and yy >= 0 and yy < n and vis[xx][yy] == 0)
                    {
                        vis[xx][yy] = 1;
                        q.push({xx, yy});
                    }
                }

                size--;
            }
        }

        return -1;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        vector<int> KnightPos(2);
        vector<int> TargetPos(2);
        int N;
        cin >> N;
        cin >> KnightPos[0] >> KnightPos[1];
        cin >> TargetPos[0] >> TargetPos[1];
        Solution obj;
        int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends