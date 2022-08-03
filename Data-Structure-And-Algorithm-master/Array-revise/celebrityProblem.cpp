// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    
    int celebrity(vector<vector<int> >& arr, int n) 
    {
        int cel=0;
        for(int i=1;i<n;i++)
        {
            if(arr[cel][i]==1)
            cel=i;
        }
        
        for(int i=0;i<n;i++)
        {
            if(i==cel)
            {
              if(arr[cel][cel]==1) return -1;
              else continue;
            }
            if(i!=cel and (arr[cel][i]==1 or arr[i][cel]==0) )
            return -1;
        }
        return cel;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}
  // } Driver Code Ends