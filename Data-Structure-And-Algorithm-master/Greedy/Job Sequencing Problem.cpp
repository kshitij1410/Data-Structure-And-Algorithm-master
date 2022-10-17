#include <bits/stdc++.h>
using namespace std;

// A structure to represent a job
struct Job
{
    int id;     // Job Id
    int dead;   // Deadline of job
    int profit; // Profit if job is over before or on deadline
};

class Solution
{
public:
    bool static cmp(pair<int, int> a, pair<int, int> b)
    {
        return a.first > b.first;
    }
    // Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n)
    {
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++)
        {
            v.push_back({arr[i].profit, arr[i].dead});
        }

        sort(v.begin(), v.end(), cmp);
        int ans = 0;
        int c = 0;
        vector<int> assign(n, 0);
        for (int i = 0; i < n; i++)
        {
            for (int j = min(n, v[i].second); j > 0; j--)
            {
                if (assign[j - 1] == 0)
                {
                    assign[j - 1] = 1;
                    ans += v[i].first;
                    c++;
                    break;
                }
            }
        }

        return {c, ans};
    }
};


int main()
{
    int t;
    // testcases
    cin >> t;

    while (t--)
    {
        int n;

        // size of array
        cin >> n;
        Job arr[n];

        // adding id, deadline, profit
        for (int i = 0; i < n; i++)
        {
            int x, y, z;
            cin >> x >> y >> z;
            arr[i].id = x;
            arr[i].dead = y;
            arr[i].profit = z;
        }
        Solution ob;
        // function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout << ans[0] << " " << ans[1] << endl;
    }
    return 0;
}

// } Driver Code Ends