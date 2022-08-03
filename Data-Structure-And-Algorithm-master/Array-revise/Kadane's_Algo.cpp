#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maxSubarraySum(int arr[], int n)
    {

        // kadane algorith
        int bestAns = arr[0];
        int sum = 0;

        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
            if (bestAns < sum)
            {
                bestAns = sum;
            }
            if (sum < 0)
            {
                sum = 0;
            }
        }

        return bestAns;
    }
};

// { Driver Code Starts.

int main()
{
    int t, n;

    cin >> t;   // input testcases
    while (t--) // while testcases exist
    {

        cin >> n; // input size of array

        int a[n];

        for (int i = 0; i < n; i++)
            cin >> a[i]; // inputting elements of array

        Solution ob;

        cout << ob.maxSubarraySum(a, n) << endl;
    }
}
// } Driver Code Ends