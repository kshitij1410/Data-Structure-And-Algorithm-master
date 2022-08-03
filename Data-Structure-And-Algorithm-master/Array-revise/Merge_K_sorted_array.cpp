// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


 // } Driver Code Ends
//User function Template for C++


class Solution
{
    public:
    typedef pair<int,pair<int,int>>ppi;
    
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int n)
    {
        
       priority_queue <ppi, vector<ppi>, greater<ppi>> q;
       
       for(int i=0;i<n;i++)
       {
           q.push({arr[i][0],{i,0}});
       }
       
       vector<int>ans;
       
       while(!q.empty())
       {
           auto it =q.top();
           ans.push_back(it.first);
           q.pop();
           int iIndx=it.second.first;
           int jIndx=it.second.second+1;
           if(jIndx<n)
           q.push({arr[iIndx][jIndx],{iIndx,jIndx}});
       }
       
       return ans;
       
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}





  // } Driver Code Ends