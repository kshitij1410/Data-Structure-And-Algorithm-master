#include <bits/stdc++.h>
using namespace std;

long long sumOfMaxAndMin(vector<int> &nums, int n, int k)
{
    deque<pair<int, int>> dqmin;
    deque<pair<int, int>> dqmax;

    long long sum = 0 * 1LL;

    for (int i = 0; i < k; i++)
    {
        // for dqmax
        while ((!dqmax.empty()) and (dqmax.back().first <= nums[i]))
        {
            dqmax.pop_back();
        }
        dqmax.push_back({nums[i], i});

        // for dqmin
        while ((!dqmin.empty()) and (dqmin.back().first >= nums[i]))
        {
            dqmin.pop_back();
        }
        dqmin.push_back({nums[i], i});
    }
    sum += dqmin.front().first + dqmax.front().first;

    for (int i = k; i < n; i++)
    {
        int index = i - k;
        
        // remove of previous index
        while ((!dqmin.empty()) and (dqmin.front().second <= index))
            dqmin.pop_front();
        while ((!dqmax.empty()) and (dqmax.front().second <= index))
            dqmax.pop_front();

        // update the min value
        while ((!dqmax.empty()) and (dqmax.back().first <= nums[i]))
        {
            dqmax.pop_back();
        }
        dqmax.push_back({nums[i], i});

        // for dqmin
        while ((!dqmin.empty()) and (dqmin.back().first >= nums[i]))
        {
            dqmin.pop_back();
        }
        dqmin.push_back({nums[i], i});

        sum += dqmin.front().first + dqmax.front().first;
    }

    return sum;
}

int main()
{
}