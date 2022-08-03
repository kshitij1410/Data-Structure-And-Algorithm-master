// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int> &nums, int n)
    {

        long long int pre[n + 1];
        long long int suff[n + 1];
        pre[0] = suff[n] = 1;

        for (int i = 1; i <= n; i++)
        {
            pre[i] = pre[i - 1] * nums[i - 1];
            suff[n - i] = suff[n - i + 1] * nums[n - i];
        }

        for (int i = 0; i < n; i++)
        {
            nums[i] = pre[i] * suff[i + 1];
        }

        return nums;
    }
};

// { Driver Code Starts.
int main()
{
    int t; // number of test cases
    cin >> t;
    while (t--)
    {
        int n; // size of the array
        cin >> n;
        vector<long long int> arr(n), vec(n);

        for (int i = 0; i < n; i++) // input the array
        {
            cin >> arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr, n); // function call

        for (int i = 0; i < n; i++) // print the output
        {
            cout << vec[i] << " ";
        }
        cout << endl;
    }
    return 0;
} // } Driver Code Ends