#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:
    
    int missingNumber(int arr[], int n)
    {
        int i = 0;
        while (i < n)
        {
            if (arr[i] <= 0)
                i++;
            else
            {
                // check the number is out of bound or not and check duplicat element
                if (n < arr[i] or i + 1 == arr[i] or arr[i] == arr[arr[i] - 1])
                {
                    // do nothing
                    i++;
                }
                else
                {
                    int temp = arr[i];
                    int val = arr[temp - 1];

                    // swap these value
                    arr[i] = val;
                    arr[temp - 1] = temp;
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (i + 1 == arr[i])
                continue;
            else
                return i + 1;
        }
        return n + 1;
    }
};

// { Driver Code Starts.

// int missingNumber(int arr[], int n);

int main()
{

    // taking testcases
    int t;
    cin >> t;
    while (t--)
    {

        // input number n
        int n;
        cin >> n;
        int arr[n];

        // adding elements to the array
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        Solution ob;
        // calling missingNumber()
        cout << ob.missingNumber(arr, n) << endl;
    }
    return 0;
} // } Driver Code Ends