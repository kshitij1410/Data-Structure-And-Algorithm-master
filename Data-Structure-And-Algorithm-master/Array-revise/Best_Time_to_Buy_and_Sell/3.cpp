
// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++


// at most 2 
int maxProfit1(vector<int> &price)
{
    int n = price.size();
    vector<int> dp(n + 2, 0);

    int maxval = price[n - 1];

    for (int i = n; i >= 1; i--)
    {
        maxval = max(maxval, price[i - 1]);
        dp[i] = max(dp[i + 1], maxval - price[i - 1]);
    }

    int minval = price[0];

    for (int i = 1; i <= n; i++)
    {
        minval = min(minval, price[i - 1]);
        dp[i] = max(dp[i - 1], price[i - 1] - minval + dp[i]);
    }

    return dp[n];
}

// buy-0/1
// caps - 0/1/2

int solve(int i, int buy, int cap, vector<int> &arr, vector<vector<vector<int>>> &dp)
{
    if (cap == 0)
        return 0;
    if (i == arr.size())
        return 0;
    if (dp[i][buy][cap] != -1)
        return dp[i][buy][cap];

    int profit;
    if (buy == 1)
    {
        profit = max(-arr[i] + solve(i + 1, 0, cap, arr, dp),
                     solve(i + 1, 1, cap, arr, dp));
    }
    else
    {
        profit = max(arr[i] + solve(i + 1, 1, cap - 1, arr, dp),
                     solve(i + 1, 0, cap, arr, dp));
    }

    return dp[i][buy][cap] = profit;
}

int maxProfit(vector<int> &arr)
{
    int n = arr.size();
    vector<vector<vector<int>>> dp(n,
                                   vector<vector<int>>(2, vector<int>(3, -1)));
    return solve(0, 1, 2, arr, dp);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n;
        cin >> n;
        vector<int> price(n);
        for (int i = 0; i < n; i++)
            cin >> price[i];
        cout << maxProfit(price) << endl;
    }
}
// } Driver Code Ends