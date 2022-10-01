//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};

class Solution
{
public:
    int tour(petrolPump p[], int n)
    {
        // time - O(n*2)  space - O(1)
        int ans = -1;
        int i = 0;
        while (i < n)
        {
            int k = i;

            int flag = 0;
            int petrol = 0;

            for (int j = k; j <= k + n; j++)
            {
                int index = j % n;
                petrol += p[index].petrol - p[index].distance;

                if (petrol < 0)
                {
                    flag = 1;
                    break;
                }
            }

            if (flag == 1)
            {
                i++;
                continue;
            }

            if (flag == 0)
            {
                ans = k;
                break;
            }
        }

        return ans;
    }
};


// time O(n), space O(1)
int tour(petrolPump p[], int n)
{
    int def = 0;
    int ansIdx = 0;
    int petrol = 0;

    for (int i = 0; i < n; i++)
    {
        petrol += p[i].petrol - p[i].distance;

        if (petrol < 0)
        {
            def += petrol;
            petrol = 0;
            ansIdx = i + 1;
        }
    }

    return def + petrol >= 0 ? ansIdx : -1;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        petrolPump p[n];
        for (int i = 0; i < n; i++)
            cin >> p[i].petrol >> p[i].distance;
        Solution obj;
        cout << obj.tour(p, n) << endl;
    }
}
