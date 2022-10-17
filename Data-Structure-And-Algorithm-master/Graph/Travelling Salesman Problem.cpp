#include <bits/stdc++.h>
using namespace std;



class Solution
{
public:

// naive apporach

    int tsp(int mask, int pos, int visited_all, vector<vector<int>> cost)
    {
        int n = cost.size();
        if (mask == visited_all)
            return cost[pos][0];

        int ans = INT_MAX;

        for (int city = 0; city < n; city++)
        {
            if ((mask & (1 << city)) == 0)
            {
                int newAns = cost[pos][city] + tsp(mask | (1 << city), city, visited_all, cost);
                ans = min(ans, newAns);
            }
        }

        return ans;
    }

    int total_cost(vector<vector<int>> cost)
    {
        int n = cost.size();
        return tsp(1, 0, (1 << n) - 1, cost);
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
        vector<vector<int>> cost(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> cost[i][j];
        Solution obj;
        int ans = obj.total_cost(cost);
        cout << ans << "\n";
    }
    return 0;
}
