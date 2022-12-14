// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int arr[], int n)
    {
        int last_digit=arr[0];
        int count=1;
        
        for(int i=1;i<n;i++)
        {
            if(last_digit!=arr[i])
            {
                if(count==1)
                last_digit=arr[i];
                else
                count--;
            }
            else 
            count++;
        }
        count=0;
        
        //check whether this element is majority or not
        for(int i=0;i<n;i++)
        {
            if(arr[i]==last_digit)
            count++;
        }
        
        if(count>n/2) return last_digit;
        else return -1;
        
        
       
    }
};

// { Driver Code Starts.

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}
  // } Driver Code Ends