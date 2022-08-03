#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // We do this by decreasing the height of all the towers towards the right by k and increasing all
    // the height of the towers towards the left (by k).
    
    int getMinDiff(int arr[], int n, int k)
    {

        sort(arr, arr + n);
        int smallest = arr[0];
        int largest = arr[n - 1];
        int ans = arr[n - 1] - arr[0];

        for (int i = 1; i < n; i++)
        {
            if (arr[i] - k < 0)
                continue;

            smallest = min(arr[0] + k, arr[i] - k);
            largest = max(arr[n - 1] - k, arr[i - 1] + k);

            ans = min(ans, largest - smallest);
        }

        return ans;
    }
    
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
} // } Driver Code Ends