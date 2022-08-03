#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    
    int findPlatform1(int arr[], int dep[], int n)
    {
        sort(arr, arr + n);
        sort(dep, dep + n);

        int mnAns = 0;
        int plat = 1;
        int i = 1;
        int j = 0;

        while (i < n and j < n)
        {
            if (arr[i] > dep[j])
            {
                plat--;
                j++;
            }
            else if (arr[i] <= dep[j])
            {
                plat++;
                i++;
            }

            mnAns = max(mnAns, plat);
        }

        return mnAns;
    }

    int findPlatform2(int arr[], int dep[], int n)
    {
       int dp[2361]={0};
       
       //inc and dec
       for(int i=0;i<n;i++)
       {
           dp[arr[i]]++;
           dp[dep[i]+1]--;
           
       }
       
       //calculate prefix 
       for(int i=1;i<2361;i++)
      {
          dp[i]=dp[i]+dp[i-1];
      }
      
      
      int mnAns=INT_MIN;
      // take out the max
      for(int i=0;i<2361;i++)
      {
          mnAns=max(mnAns,dp[i]);
      }
    	return mnAns;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        int dep[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        for (int j = 0; j < n; j++)
        {
            cin >> dep[j];
        }
        Solution ob;
        cout << ob.findPlatform(arr, dep, n) << endl;
    }
    return 0;
} 