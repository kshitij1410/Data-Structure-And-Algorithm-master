//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// 4 6
// adac
// adadac
// code output-3
// actua output-4

/// XXXXXXXXXXXXXXXXXXXXX----------WRONG SOl -----------XXXXXXXXXXXXXXXXXXX
class Solution
{
public:
    int longestCommonSubstr(string s1, string s2, int n, int m)
    {
        string res = "";
        for (int i = 0; i < n; i++)
        {
            int j = i;
            string ans = "";
            for (int k = 0; k < m; k++)
            {
                if (s1[j] == s2[k])
                {
                    ans += s2[k];
                    j++;
                }
                else
                {
                    ans = "";
                    j = i;
                }

                if (res.size() < ans.size())
                    res = ans;
            }
        }

        return res.size();
    }
};

int longestCommonSubstr(string s1, string s2, int n, int m)
{
    int ans = 0;
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                ans = max(ans, dp[i][j]);
            }
            else
                dp[i][j] = 0;
        }
    }

    return ans;
}


int lcs(int i, int j, int count)
{
 
    if (i == 0 || j == 0)
        return count;
 
    if (X[i - 1] == Y[j - 1]) {
        count = lcs(i - 1, j - 1, count + 1);
    }
    count = max(count,
                max(lcs(i, j - 1, 0),
                    lcs(i - 1, j, 0)));
    return count;
}
 

 
//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr(s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends