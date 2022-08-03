#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minJumps(int arr[], int n)
    {
        if (n == 1)
            return 0;
        int jumps = 1; //[6,1,1]
        if (arr[0] == 0)
            return -1;
        int mxR = arr[0];
        int steps = arr[0];

        for (int i = 1; i < n; i++)
        {
            if (i == n - 1)
                return jumps;

            mxR = max(mxR, arr[i] + i);
            steps--;

            if (steps == 0)
            {
                jumps++;
                if (i >= mxR)
                    return -1;
                steps = mxR - i;
            }
        }

        return jumps;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, i, j;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution obj;
        cout << obj.minJumps(arr, n) << endl;
    }
    return 0;
}
