#include <bits/stdc++.h>
// #define fastin ios_base::sync_with_stdio(false);cin.tie(NULL);

#define mod 1000000007
using namespace std;

int solve(vector <int>arr, int a, int b)
{
    unordered_set<int>set2;
    unordered_map<int, int> map;
    int t = a;
    int c = 1;
    while (true)
    {
        if (map.find(t) != map.end())
            break;
        if (t == -1)
            break;
        map[t] = c++;
        t = arr[t];
    }
    for(auto ele:map)
    {
        cout<<ele.first<<" "<<ele.second<<endl;
    }

    t = b;
    int j = 0;
    int min = INT_MAX;
    int ans = -1;
    while (true)
    {
        if (set2.find(t) != set2.end())
            break;
        if (t == -1)
            break;
        if (map[t] == 0)
        {
            j++;
            set2.insert(t);
            t = arr[t];
            continue;
        }
        int sum = map[t] + j++;
        if (sum < min)
        {  
            cout<<t<<" "<<map[t]<<" "<<j<<endl;
            min = sum;
            ans = t;
        }
        set2.insert(t);
        t = arr[t];
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int a, b;
    cin >> a >> b;
    cout << solve(arr, a, b);

    return 0;
}