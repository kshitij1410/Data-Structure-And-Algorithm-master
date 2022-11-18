class Solution {
public:
    bool rotateString(string s, string goal) {
         if(s.length()!=goal.length()) return false;
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s==goal) return true;
            string ans =s.substr(1,n-1)+s[0];
            s=ans;
        }
        return false;
    }
};