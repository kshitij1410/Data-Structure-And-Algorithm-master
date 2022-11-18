
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC-O(n) and space O(n)
    int minimumNumberOfSwaps(string str)
    {
        vector<int> v;
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == '[')
                v.push_back(i);
        }
        int j = 0;
        int count = 0;
        int ans = 0;
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == '[')
            {
                j++;
                count++;
            }
            else if (str[i] == ']')
            {
                count--;
            }

            if (count < 0)
            {
                ans += v[j] - i;
                swap(str[i], str[v[j]]);
                j++;
                count = 1;
            }
        }

        return ans;
    }

    // Tc-O(n) , space O(1)
    long swapCount(string chars)
    {

        int countLeft = 0, countRight = 0;

        int swap = 0, imbalance = 0;

        for (int i = 0; i < chars.length(); i++)
        {
            if (chars[i] == '[')
            {

                countLeft++;

                if (imbalance > 0)
                {

                    swap += imbalance;

                    imbalance--;
                }
            }
            else if (chars[i] == ']')
            {

                countRight++;
                imbalance = (countRight - countLeft);
            }
        }
        return swap;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.minimumNumberOfSwaps(S) << endl;
    }
    return 0;
}
// } Driver Code Ends