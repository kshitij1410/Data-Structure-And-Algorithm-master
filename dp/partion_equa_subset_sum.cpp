class Solution{
public:
   int sove(int arr[],int n,int temp)
   {
    //   if(temp==0) return 1;
    //   if(i==0) return 0;
       
       
    //   //don't pick
    //   int a = sove(arr,i-1,temp);
       
    //   //pick
    //   if(temp>=arr[i-1])
    //   a=a || sove(arr,i-1,temp-arr[i-1]);
       
    //   return a;
    int dp[n+1][temp+1];
    for(int i=0;i<=temp;i++) dp[0][i]=0;
    for(int i=0;i<=n;i++) dp[i][0]=1;
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=temp;j++)
        {
            dp[i][j]=dp[i-1][j];
            
            if(j>=arr[i-1])
            dp[i][j]=dp[i][j] || dp[i-1][j-arr[i-1]];
        }
    }
    return dp[n][temp];
     
   }
   
    int equalPartition(int n, int arr[])
    {
        int sum=0;
        for(int i=0;i<n;i++)
        sum+=arr[i];
        
        if(sum%2!=0) return 0;
        else
        {
            int temp=sum/2;
            return sove(arr,n,temp);
        }
    }