
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findMaxLen(string s) {
        stack<int>st;
        st.push(-1);
        int ans=0;
        
        for(int i=0;i<s.size();i++)
        {
           if(s[i]=='(')
           st.push(i);
           else{
               
               // case 1
               st.pop();
               
               if(st.empty())
               {
                   st.push(i);
               }
               else{
                   ans=max(ans,i-st.top());
               }
           }
        }
        
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S; 
        Solution ob;
        cout << ob.findMaxLen(S) << endl;
    }
    return 0;
}
