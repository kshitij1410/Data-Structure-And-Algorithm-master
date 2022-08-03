// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int findSubString(string str)
    {
        set<char> s;
        for (int i = 0; i < str.size(); i++)
        {
            s.insert(str[i]);
        }
        int uniq = s.size();

        unordered_map<char, int> mp;

        for (int i = 0; i < uniq; i++)
        {
            mp[str[i]]++;
        }

        int ans = INT_MAX;
        if (mp.size() == uniq)
            ans = uniq;
            

        int i = uniq;
        int j = 0;
        for (int i = uniq; i < str.size(); i++)
        {
            mp[str[i]]++;
            while (mp.size() == uniq)
            {
                ans = min(ans, i - j + 1);
                mp[str[j]]--;
                if (mp[str[j]] == 0)
                    mp.erase(str[j]);
                j++;
            }
        }

        return ans;
    }
};

// { Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
} // } Driver Code Ends