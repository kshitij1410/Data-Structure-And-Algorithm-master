
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string removeDuplicates(string str)
    {
        string ans = "";
        unordered_map<char, int> mp;
        // bcz find method takes O(n * n) for loop
        //  so we use unordered_map that take O(1) in look up operation

        for (int i = 0; i < str.size(); i++)
        {
            if (mp.find(str[i]) == mp.end())
            {
                ans += str[i];
                mp[str[i]]++;
            }
        }

        return ans;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        Solution ob;
        auto ans = ob.removeDuplicates(str);

        cout << ans << "\n";
    }
    return 0;
}