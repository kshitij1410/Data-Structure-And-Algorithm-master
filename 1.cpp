#include<bits/stdc++.h>
using namespace std;

int maxDistance(vector<pair<int, int>> adj[], int v, int src)
{
    // dist,node
    vector<int>dist(v+1,INT_MIN);

    priority_queue<pair<int, int>> pq;
    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty())
    {
        int nodeDis = pq.top().first;
        int nodeVal = pq.top().second;
        pq.pop();
        for (auto nbr : adj[nodeVal])
        {
            int temp1 = nbr.first;  // nodeval
            int temp2 = nbr.second; // node dis
            if (dist[temp1] == INT_MAX)
            {
                int val = nodeDis + temp2;
                pq.push({val, temp1});
            }

            dist[temp1] = max(nodeDis + temp2, dist[temp1]);
        }
    }

   int ans=0;
   for(int i=0;i<dist.size();i++)
   {
     if(ans<dist[i])
     {
        ans=dist[i];
     }
   }

   return ans;

}

void addEdge(vector<pair<int, int>> adj[], int u, int v, int wei)
{
    adj[u].push_back({v, wei});
    adj[v].push_back({u, wei});
}


int solve(int n, int m,vector<int>a,vector<int>x,vector<int>y)
{    

    vector<pair<int, int>> adj[m];
    for(int i=0;i<x.size();i++)
    {
        addEdge(adj, x[i], y[i], a[x[i]-1]-a[y[i]-1]);
    }
   
    return maxDistance(adj,n, 1);

  

}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];

    printlIS(arr,n);
    return 0;
}

