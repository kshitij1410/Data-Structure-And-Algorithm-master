//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// problem occur when n=3
// x=2 y=2 z=2
// output 0

// } Driver Code Ends


class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        // if(n==0) return 0;
        
        // int a=0;
        // // cut of x
        // if(n>=x)
        // a=max(a,1+maximizeTheCuts(n-x,x,y,z));
        
        // //cut of y
        // if(n>=y)
        // a=max(a,1+maximizeTheCuts(n-y,x,y,z));
        
        // //cut of z
        // if(n>=z)
        // a=max(a,1+maximizeTheCuts(n-z,x,y,z));
        
        // return a;
        
        
        int dp[n+1]={0};
       
        
        for(int i=1;i<=n;i++)
        {
             if(i>=x)
             {
                 if(i==x || dp[i-x]!=0)
                 dp[i]=1+dp[i-x];
             }
             
             
             if(i>=y)
             {
                 if(i==y || dp[i-y]!=0)
                 dp[i]=max(dp[i],1+dp[i-y]);
             }
             
             
             if(i>=z)
             {
                 if(i==z || dp[i-z]!=0)
                 dp[i]=max(dp[i],1+dp[i-z]);
             }
             
             
        }
        
        return dp[n];
    }
};

//{ Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}
// } Driver Code Ends