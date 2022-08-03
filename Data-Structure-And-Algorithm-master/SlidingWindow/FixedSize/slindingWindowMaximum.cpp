// You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

// Return the max sliding window.

 

// Example 1:

// Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
// Output: [3,3,5,5,6,7]
// Explanation: 
// Window position                Max
// ---------------               -----
// [1  3  -1] -3  5  3  6  7       3
//  1 [3  -1  -3] 5  3  6  7       3
//  1  3 [-1  -3  5] 3  6  7       5
//  1  3  -1 [-3  5  3] 6  7       5
//  1  3  -1  -3 [5  3  6] 7       6
//  1  3  -1  -3  5 [3  6  7]      7


//Method 1: Naive approach O(k*nums.size())
//method 2: Avl tree or priority queue O(N log k)  and space O(k)
// Method 3: deque Tc- O(n) and sc-O(k) 

// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
       deque<int>dq;
       vector<int>ans;
       
       for(int i=0;i<k;i++)
       {
           while(!dq.empty() and arr[i]>=arr[dq.back()])
           dq.pop_back();
           
           dq.push_back(i);
           
       }
       
       ans.push_back(arr[dq.front()]);
       
       for(int i=k;i<n;i++)
       {
           while(!dq.empty() and i-k>=dq.front())
           dq.pop_front();
           
           while(!dq.empty() and arr[i]>=arr[dq.back()])
           dq.pop_back();
           
           dq.push_back(i);
           
           ans.push_back(arr[dq.front()]);
       }
       
       return ans;
    }
};

// { Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, k;
	    cin >> n >> k;
	    
	    int arr[n];
	    for(int i = 0;i<n;i++) 
	        cin >> arr[i];
	    Solution ob;
	    vector <int> res = ob.max_of_subarrays(arr, n, k);
	    for (int i = 0; i < res.size (); i++) 
	        cout << res[i] << " ";
	    cout << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends