
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solveWordWrap(vector<int> nums, int k)
    {
        int n = nums.size();
        // next 2 for loop is used to calculate cost of putting words from
        // i to j in one line. If words don't fit in one line then we put
        // Integer.MAX_VALUE there.

        vector<vector<int>> cost(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i > j)
                    continue;

                if (i == j)
                {
                    cost[i][j] = k - nums[j];
                }
                else
                {
                    cost[i][j] = cost[i][j - 1] - nums[j] - 1;
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (cost[i][j] < 0)
                    cost[i][j] = INT_MAX;
                else if (cost[i][j] >= 0 and j == n - 1)
                    cost[i][j] = 0;
                else
                {
                    cost[i][j] = cost[i][j] * cost[i][j];
                }
            }
        }
       
        // minCost from i to len is found by trying
        // j between i to len and checking which
        // one has min value
        vector<int> minCost(n, 0);
        vector<int> result(n, 0);

        for (int i = n - 1; i >= 0; i--)
        {
            minCost[i] = cost[i][n - 1];
            result[i] = n;

            for (int j = n - 1; j > i; j--)
            {
                if (cost[i][j - 1] == INT_MAX)
                    continue;

                if (minCost[i] > cost[i][j - 1] + minCost[j])       //from (i-->j-1) + (j)
                {
                    minCost[i] = cost[i][j - 1] + minCost[j];
                    result[i] = j;
                }
            }
        }

        return minCost[0];
    }
};

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, k;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i];
        cin >> k;
        Solution obj;
        cout << obj.solveWordWrap(nums, k) << endl;
    }
    return 0;
} // } Driver Code Ends