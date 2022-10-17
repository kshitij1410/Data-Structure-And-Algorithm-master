#include <bits/stdc++.h>
using namespace std;

// undirected graph
void addEdge(vector<vector<int>> adj[], int u, int v, int wei)
{
    adj[u].push_back({v, wei});
    adj[v].push_back({u, wei});
}

// calculate shortest distance using bfs

//only bfs not work we have to use dijkistra algorithm

vector<int> dijkstra(int n, vector<vector<int>> g[], int source)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> distTo(n, INT_MAX);
    distTo[source] = 0;
    pq.push(make_pair(0, source));
    while (!pq.empty())
    {
        int dist = pq.top().first;
        int prev = pq.top().second;
        pq.pop();

        for (int i = 0; i < g[prev].size(); i++)
        {
            int next = g[prev][i][0];
            int nextDist = g[prev][i][1];
            if (distTo[next] > distTo[prev] + nextDist)
            {
                distTo[next] = distTo[prev] + nextDist;
                pq.push(make_pair(distTo[next], next));
            }
        }
    }

    return distTo;
}

int main()
{
    int v = 5;
    vector<vector<int>> adj[v];

    addEdge(adj, 0, 1, 7);
    addEdge(adj, 0, 3, 2);
    addEdge(adj, 0, 2, 1);
    addEdge(adj, 1, 3, 5);
    addEdge(adj, 3, 4, 7);
    addEdge(adj, 1, 4, 1);
    addEdge(adj, 2, 1, 3);

    dijkstra(v, adj, 0);

    return 0;
}
