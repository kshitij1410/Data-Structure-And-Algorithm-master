#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lenOfLongSubarr(int arr[], int n, int k)
    {
        // calculate prefix sum and use it
        int sum = 0;
        int ans = 0;
        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++)
        {
            sum += arr[i];

            if (sum == k)
                ans = i + 1;
            
            //don't take duplicate value bcz we have to maximize the length
            if (mp.find(sum) == mp.end())
                mp[sum] = i;

            if (mp.find(sum - k) != mp.end())
            {
                ans = max(ans, i - mp[sum - k]);
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
        int n, k;
        cin >> n >> k;
        int a[n];

        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution ob;
        cout << ob.lenOfLongSubarr(a, n, k) << endl;
    }

    return 0;
} 