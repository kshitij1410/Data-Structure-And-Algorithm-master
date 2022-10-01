#include<bits/stdc++.h>
using namespace std;

void printlIS(int arr[],int n)
{
    vector<int>hash(n),dp(n,1);
    int idx=0;
    int mx=0;

    for(int i=0;i<n;i++)
    {
        hash[i]=i;
        for(int j=0;j<i;j++)
        {
              if(arr[i]>arr[j] and dp[i]<dp[j]+1)
              {
                  dp[i]=dp[j]+1; 
                  hash[i]=j;
              }
        }

        if(mx<dp[i])
        {
            idx=i;
            mx=dp[i];
        }
    }
  int ans[mx];
  int i=mx-1;

   while(i>=0)
   {
        ans[i]=arr[idx];
        i--;
        idx=hash[idx];
   }

   for(int i=0;i<mx;i++) cout<<ans[i]<<" ";
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];

    printlIS(arr,n);
    return 0;
}