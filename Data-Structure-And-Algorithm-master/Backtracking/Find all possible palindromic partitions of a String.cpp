//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
   bool isPalindrom(string str)
   {
       int n=str.size();
       if(n==1) return true;
       int i=0;
       int j=n-1;
       while(i<j)
       {
           if(str[i]!=str[j]) return false;
           i++;
           j--;
       }
       
       return true;
   }
   void solve(vector<vector<string>>&res,vector<string>&temp,int idx,string str,int n)
   {
       //base case
       if(idx==n)
       {
         res.push_back(temp);
         return;
       }
       
       string s="";
       for(int i=idx;i<n;i++)
       {
           s+=str[i];
           if(isPalindrom(s)==true)
           {
               temp.push_back(s);
               solve(res,temp,i+1,str,n);
               temp.pop_back();
           }
       }
   }
  
    vector<vector<string>> allPalindromicPerms(string S) {
         vector<string>temp;
         vector<vector<string>>res;
         solve(res,temp,0,S,S.size());
         return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        
        cin>>S;

        Solution ob;
        vector<vector<string>> ptr = ob.allPalindromicPerms(S);
        
        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                cout<<ptr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends