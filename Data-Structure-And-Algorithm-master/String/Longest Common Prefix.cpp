class Solution {
public:
    string longestCommonPrefix(vector<string>& str) {
        int n=str.size();
        int size=str[0].size();
        string temp=str[0];
        for(int i=1;i<n;i++)
        {
           string t=str[i];
           string ans="";
           for(int j=0;j<min(temp.size(),t.size());j++)
           {
               if(temp[j]!=t[j])
                  break;
                else
                ans+=temp[j];
           }
           temp=ans;
        }

        return temp;
    }
};