#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxSubStr(string str)
    {
        int zero = 0;
        int one = 0;
        int ans = 0;
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == '0')
                zero++;
            if (str[i] == '1')
                one++;

            if (zero == one)
                ans++;

            if (i == str.size() - 1)
            {
                if (zero != one)
                    ans = -1;
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
        int ans = ob.maxSubStr(str);
        cout << ans << endl;
    }
    return 0;
}

