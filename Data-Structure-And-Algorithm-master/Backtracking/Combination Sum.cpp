//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    // Function to return a list of indexes denoting the required
    // combinations whose sum is equal to given number.
    void solve(vector<vector<int>> &res, vector<int> &temp, vector<int> arr, int b, int i)
    {
        // base case
        if (i == arr.size())
            return;
        if (b == 0)
        {
            res.push_back(temp);
            return;
        }

        // pick
        if (b >= arr[i])
        {
            temp.push_back(arr[i]);
            solve(res, temp, arr, b - arr[i], i);
            temp.pop_back();
        }

        // don't pick
        solve(res, temp, arr, b, i + 1);
    }

    vector<vector<int>> combinationSum(vector<int> &A, int B)
    {

        vector<vector<int>> res;
        set<int> s(A.begin(), A.end());
        vector<int> v;
        for (auto e : s)
            v.push_back(e);
        vector<int> temp;
        solve(res, temp, v, B, 0);
        return res;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> A;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            A.push_back(x);
        }
        int sum;
        cin >> sum;
        Solution ob;
        vector<vector<int>> result = ob.combinationSum(A, sum);
        if (result.size() == 0)
        {
            cout << "Empty";
        }
        for (int i = 0; i < result.size(); i++)
        {
            cout << '(';
            for (int j = 0; j < result[i].size(); j++)
            {
                cout << result[i][j];
                if (j < result[i].size() - 1)
                    cout << " ";
            }
            cout << ")";
        }
        cout << "\n";
    }
}
// } Driver Code Ends