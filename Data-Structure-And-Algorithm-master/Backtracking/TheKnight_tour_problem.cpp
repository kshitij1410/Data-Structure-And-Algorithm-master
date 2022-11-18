#include <bits/stdc++.h>
using namespace std;
int n = 8;
int dx[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int dy[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
bool solve(int chess[8][8], int i, int j, int val, int total)
{
    chess[i][j] = val;

    // base case
    if (total == val)
        return true;

    for (int k = 0; k < 8; k++)
    {
        int xt = dx[k] + i;
        int yt = dy[k] + j;

        if (xt >= 0 and xt < n and yt >= 0 and yt < n and chess[xt][yt] == -1)
        {
            bool temp = solve(chess, xt, yt, val + 1, total);
            if (temp == false)
                chess[xt][yt] = -1;
            else
                return temp;
        }
    }

    return false;
}

int main()
{

    // vector<vector<int>> chess(n, vector<int>(n, -1));
    int chess[8][8];
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            chess[i][j] = -1;
        }
    }
    int total = n * n - 1;
    solve(chess, 0, 0, 0, total);
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            cout << chess[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;
}