//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        stack<char>s;
        for(int i=0;i<x.size();i++)
        {
            if(x[i]=='{' or x[i]=='(' or x[i]=='[')
            s.push(x[i]);
            
            else if(x[i]==')' and s.size()>0)
            {
                char temp=s.top();
                if(temp=='(')
                s.pop();
                else
                return false;
            }
             else if(x[i]=='}' and s.size()>0)
            {
                char temp=s.top();
                if(temp=='{')
                s.pop();
                else
                return false;
            }
             else if(x[i]==']' and s.size()>0)
            {
                char temp=s.top();
                if(temp=='[')
                s.pop();
                else
                return false;
            }
            else{
                return false;
            }
        }
        if(s.size()==0)
        return true;
        return false;
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends