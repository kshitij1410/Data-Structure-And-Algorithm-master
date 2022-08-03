// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                            long long int n, long long int k);


int main()
{
    long long int t, i;
    cin >> t;
    while (t--)
    {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans)
            cout << it << " ";
        cout << endl;
    }
    return 0;
}

// navie approach O(N*k) for each and every window to have to check negative value in traversal

// optimize approach O(n) and space O(k) 
//i use queue to store negative value  and use concept of sliding window 


vector<long long> printFirstNegativeInteger(long long int arr[],
                                            long long int n, long long int k)
{

    queue<int> q;
    vector<long long> ans;

    for (int i = 0; i < k; i++)
    {
        if (arr[i] < 0)
            q.push(arr[i]);
    }

    if (q.empty())
        ans.push_back(0);
    else
        ans.push_back(q.front());

    for (int i = k; i < n; i++)
    {
        if (arr[i] < 0)
            q.push(arr[i]);

        if (q.front() == arr[i - k])
            q.pop();

        if (q.empty() == true)
        {
            ans.push_back(0);
        }
        else
            ans.push_back(q.front());
    }

    return ans;
}