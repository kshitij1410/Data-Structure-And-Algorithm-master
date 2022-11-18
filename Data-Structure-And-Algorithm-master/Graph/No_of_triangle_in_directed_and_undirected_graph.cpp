#include <bits/stdc++.h>
using namespace std;
int main()
{
    int v;
    cin >> v;
    vector<vector<int>> graph;
    for (int i = 0; i < v; i++)
    {
        vector<int> temp;
        for (int j = 0; j < v; j++)
        {
            int val;
            cin >> val;
            temp.push_back(val);
        }
        graph.push_back(temp);
    }
    int countTri = 0;

    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            for (int k = 0; k < v; k++)
            {
                if (i != j and j != k and k != i)
                {
                    if (graph[i][j] and graph[j][k] and graph[k][i])
                        countTri++;
                }
            }
        }
    }
    bool dir = false;
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            if (graph[i][j] and !graph[j][i])
                dir = true;
        }
    }

    if (dir == true)
        cout << (countTri / 3) << "\n";
    else
        cout << (countTri / 6) << "\n";

    return 0;
}