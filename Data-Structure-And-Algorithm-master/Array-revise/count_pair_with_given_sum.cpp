// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
//this case for only not distinct element but if the element is distinct then we can use unordered_set

    int getPairsCount(int arr[], int n, int k)
    {
        unordered_map<int, int> mp;
        // val,freq;
        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            if (mp.find(k - arr[i]) != mp.end())
            {
                ans += mp[k - arr[i]];
            }
            mp[arr[i]]++;
        }

        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getPairsCount(arr, n, k);
        cout << ans << "\n";
    }

    return 0;
} // } Driver Code Ends