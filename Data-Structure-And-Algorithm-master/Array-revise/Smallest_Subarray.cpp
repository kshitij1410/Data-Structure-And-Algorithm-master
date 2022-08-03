#include <bits/stdc++.h>
using namespace std;


class Solution
{
public:
    int smallestSubWithSum(int arr[], int n, int x)
    {
        int len = 0;
        int sum = 0;
        int ans = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
            len++;
            if (sum > x)
            {
                while (sum > x)
                {
                    sum = sum - arr[i + 1 - len];
                    len--;
                }

                ans = min(ans, len + 1);
            }
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
        int n, x;
        cin >> n >> x;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution obj;
        cout << obj.smallestSubWithSum(a, n, x) << endl;
    }
    return 0;
}