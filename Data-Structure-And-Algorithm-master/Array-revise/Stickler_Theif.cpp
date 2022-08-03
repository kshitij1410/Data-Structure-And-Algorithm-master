// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
public:
    // recursive approach time-O(2^n);

    int findMax(int arr[], int n)
    {
        // base case
        if (n == 1)
            return arr[0];
        if (n == 0)
            return 0;

        // pick
        int ans1 = findMax(arr, n - 2) + arr[n - 1];

        // don't pick

        int ans2 = findMax(arr, n - 1);

        return max(ans1, ans2);
    }

    // dp approach time-O(N) and space O(n)
    int FindMaxSum(int arr[], int n)
    {
        int dp[n + 1];
        dp[0] = 0;
        dp[1] = arr[0];

        for (int i = 2; i <= n; i++)
        {
            // pick this
            dp[i] = dp[i - 2] + arr[i - 1];

            // don't pick this
            dp[i] = max(dp[i], dp[i - 1]);
        }

        return dp[n];
    }
};

// { Driver Code Starts.
int main()
{
    // taking total testcases
    int t;
    cin >> t;
    while (t--)
    {
        // taking number of houses
        int n;
        cin >> n;
        int a[n];

        // inserting money of each house in the array
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        Solution ob;
        // calling function FindMaxSum()
        cout << ob.FindMaxSum(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends