#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Tle-

    // long long int solve(string str,int i,int j )
    //     {
    //         if(i>j) return 0;
    //         if(i==j) return 1;

    //         if(dp[i][j]!=-1) return dp[i][j];

    //         if(str[i]==str[j])
    //         {
    //             return dp[i][j]=1+solve(str,i+1,j)+solve(str,i,j-1);
    //         }
    //         else{
    //             return dp[i][j]=solve(str,i+1,j)+solve(str,i,j-1)-solve(str,i+1,j-1);
    //         }
    //     }

    long long int mod = 1e9 + 7;
    long long int countPS(string str)
    {
        int n = str.size();

        long long int dp[n][n];

        // gap means for length 1,2,3...n char
        for (int gap = 0; gap < n; gap++)
        {
            for (int i = 0; i < n - gap; i++)
            {
                int j = i + gap;

                if (gap == 0)
                {
                    dp[i][j] = 1;
                }
                else if (gap == 1)
                {
                    if (str[i] == str[j])
                        dp[i][j] = 3;
                    else
                        dp[i][j] = 2;
                }
                else
                {
                    // more than 3
                    if (str[i] == str[j])
                    {
                        dp[i][j] = 1 + dp[i + 1][j] + dp[i][j - 1];
                    }
                    else
                    {
                        dp[i][j] = dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1];
                    }
                }
                dp[i][j] = dp[i][j] + mod;
                dp[i][j] = (dp[i][j] % mod);
            }
        }

        long long int ans = dp[0][n - 1];
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
        long long int ans = ob.countPS(str);
        cout << ans << endl;
    }
} // } Driver Code Ends