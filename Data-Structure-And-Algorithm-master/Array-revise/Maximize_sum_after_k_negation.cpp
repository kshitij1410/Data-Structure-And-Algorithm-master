#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Logic : O(n* log n) ,space O(1)
    // smallest negative value ----> largest value (sort)
    // then convert negative value to positive if k!=0
    // if k is then i can't change the negative value to positive
    // if i convert alll the negative number to positive or if k value is not equal to zero then
    // if k valwe is even then we perform +ve, -ve operation simuntauseoly
    // if k value is odd then in order to maximize the ans we need to remove the samllest value from ans;

    long long int maximizeSum(long long int a[], int n, int k)
    {
        sort(a, a + n);
        long long int sum = 0;
        long long int temp = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            if (a[i] < 0)
            {
                if (k != 0)
                {
                    sum += (-1) * (a[i]);
                    k--;
                }
                else
                {
                    sum += a[i];
                }

                temp = min(temp, abs(a[i]));
            }
            else
            {
                sum += a[i];
                temp = min(temp, a[i]);
            }
        }

        if (k != 0)
        {
            if (k % 2 == 0)
                return sum;
            else
            {
                sum -= 2 * temp;
                return sum;
            }
        }
        else
        {
            return sum;
        }
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
        long long int a[n + 5];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        Solution ob;
        cout << ob.maximizeSum(a, n, k) << endl;
    }

    return 0;
}