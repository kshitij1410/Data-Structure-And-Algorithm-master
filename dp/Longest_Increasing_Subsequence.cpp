//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// O(N*2) solution
class Solution
{
public:
    // Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
        vector<int> dp(n, 1);
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (a[j] < a[i] and dp[j] + 1 > dp[i])
                    dp[i] = dp[j] + 1;
            }

            ans = max(ans, dp[i]);
        }

        return ans; 
    }

    // O(nlog(n))  -- binary search
    int longestSubsequence(int n, int a[])
    {
        vector<int> ans;
        ans.push_back(a[0]);

        for (int i = 1; i < n; i++)
        {
            if (ans.back() < a[i])
            {
                ans.push_back(a[i]);
            }
            else
            {
                int idx = lower_bound(ans.begin(), ans.end(), a[i]) - ans.begin();
                ans[idx] = a[i];
            }
        }

        return ans.size();
    }
};

//{ Driver Code Starts.
int main()
{
    // taking total testcases
    int t, n;
    cin >> t;
    while (t--)
    {
        // taking size of array
        cin >> n;
        int a[n];

        // inserting elements to the array
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution ob;
        // calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends