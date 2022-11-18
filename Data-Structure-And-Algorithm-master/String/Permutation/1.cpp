#include <bits/stdc++.h>
using namespace std;

class Solution
{
    // vector<string> find_permutation(string S)
    // {
    //     vector<string> s;

    //     sort(S.begin(), S.end());
    //     s.push_back(S);

    //     while (next_permutation(S.begin(), S.end()))
    //     {
    //         s.push_back(S);
    //     }
    //     return s;
    // }
public:
    vector<string> helper(vector<string> &arr, string &S, int pos)
    {

        if (pos >= S.size())
        {

            arr.push_back(S);
        }

        for (int i = pos; i < S.size(); i++)
        {
            // if we want a unique element
            while (i + 1 < S.size() && S[i] == S[i + 1])
            {

                i++;
            }
            swap(S[i], S[pos]);

            helper(arr, S, pos + 1);

            swap(S[i], S[pos]);
        }

        return arr;
    }

    vector<string> find_permutation(string S)

    {

        vector<string> arr;
        sort(S.begin(), S.end());

        helper(arr, S, 0);
        sort(arr.begin(), arr.end());
        return arr;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S;
        cin >> S;
        Solution ob;
        vector<string> ans = ob.find_permutation(S);
        cout << ans.size() << " ";
        for (auto i : ans)
        {
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}
