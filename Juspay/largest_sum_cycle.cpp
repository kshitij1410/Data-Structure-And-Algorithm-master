#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &maze, int n)
{
    int maxSum = -1;

    for (int i = 0; i < n; i++)
    {
        int node = i;
        int sum = 0;
        unordered_set<int> visited;

        while (node < n && node >= 0 && i != maze[node] && visited.count(node) == 0)
        {
            visited.insert(node);
            sum += node;
            node = maze[node];
        }

        if (node >= 0 && node < n && i == maze[node])
        {
            maxSum = max(maxSum, sum);
        }
    }

    return maxSum;
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << solve(arr, n);

    return 0;
}