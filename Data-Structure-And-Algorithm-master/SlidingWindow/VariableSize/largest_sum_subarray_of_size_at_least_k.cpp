#include <bits/stdc++.h>
using namespace std;

long long int maxSumWithK(long long int a[], long long int n, long long int k);

int main()
{
    long long int t;
    cin >> t;
    while (t--)
    {
        long long int n, k, i;
        cin >> n;
        long long int a[n];
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        cin >> k;
        cout << maxSumWithK(a, n, k) << endl;
    }
    return 0;
}


long long int maxSumWithK(long long int a[], long long int n, long long int k)
{
    long long int sum = 0;
    long long int ans = INT_MIN;

    for (long long int i = 0; i < k; i++)
        sum += a[i];

    ans = max(sum, ans);
    long long int last = 0;
    long long int j = 0;

    for (long long int i = k; i < n; i++)
    {
        sum += a[i];

        ans = max(ans, sum);
        last += a[j];
        j++;

        if (last < 0)
        {
            sum = sum - last;
            ans = max(ans, sum);
            last = 0;
        }
    }
    return ans;
}