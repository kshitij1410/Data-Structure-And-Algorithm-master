// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    int countSubArrayProductLessThanKOpt(const vector<int> &a, int n, long long k)
    {

        int l = 0;
        int r = 0;
        int ans = 0;
        long long int pro = 1;
        while (r < a.size())
        {
            pro *= a[r];
            while (pro >= k)
            {
                pro /= a[l];
                l++;
            }
            ans = ans + r - l + 1;
            r++;
        }
        return ans;
    }

    int countSubArrayProductLessThanK(const vector<int> &a, int n, long long k)
    {

        long long ans = 0;
        int i = 0;
        long long sum = 1;

        for (int j = 0; j < n; j++)
        {
            sum = sum * a[j];
            if (sum < k)
            {
                if (j == n - 1)
                {
                    int t = (j - i + 1);
                    ans += ((t * (t + 1)) / 2);
                }
                continue;
                // do nothing
            }
            else
            {
                // previous sunarray
                int t = (j - i);
                ans += ((t * (t + 1)) / 2);

                // sum is greater than equal to k
                while (sum >= k)
                {
                    sum = sum / a[i];
                    i++;
                }

                // common element reduction
                if (i < j)
                {
                    t = j - i;
                    ans = ans - (t * (t + 1)) / 2;
                }

                if (j == n - 1)
                {
                    if (i <= j)
                    {
                        t = (j - i + 1);
                        ans += ((t * (t + 1)) / 2);
                    }
                }
            }

            //   cout<<"ans"<<ans<<" "<<"j"<<j<<endl;
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
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++)
            cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}
// } Driver Code Ends