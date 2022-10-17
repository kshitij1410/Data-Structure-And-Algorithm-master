#include <bits/stdc++.h>
using namespace std;

/*

Given a weighted undirected graph G and an integer S, the task is to print the distances of the shortest paths and the count of the number of the shortest paths for each node from a given vertex, S.

Examples:

Input: S =1, G = 




Output: Shortest Paths distances are : 0 1 2 4 5 3 2 1 3 
Numbers of the shortest Paths are: 1 1 1 2 3 1 1 1 2 
Explanation:

The distance of the shortest paths to vertex 1 is 0 and there is only 1 such path, which is {1}.
The distance of the shortest paths to vertex 2 is 1 and there is only 1 such path, which is {1→2}.
The distance of the shortest paths to vertex 3 is 2 and there is only 1 such path, which is {1→2→3}.
The distance of the shortest paths to vertex 4 is 4 and there exist 2 such paths, which are {{1→2→3→4}, {1→2→3→6→4}}.
The distance of the shortest paths to vertex 5 is 5 and there exist 3 such paths, which are {{1→2→3→4→5}, {1→2→3→6→4→5}, {1→2→3→6→5}}.
The distance of the shortest paths to vertex 6 is 3 and there is only 1 such path, which is {1→2→3→6}.
The distance of the shortest paths to vertex 7 is 2 and there is only 1 such path, which is {1→8→7}.
The distance of the shortest paths to vertex 8 is 1 and there is only 1 such path, which is {1→8}.
The distance of the shortest paths to vertex 9 is 3 and there exist 2 such paths, which are {{1→8→9}, {1→2→3→9}}.


*/


// undirected graph
void addEdge(vector<vector<int>> adj[], int u, int v, int wei)
{
    adj[u].push_back({v, wei});
    adj[v].push_back({u, wei});
}


void dijkstra(int n, vector<vector<int>> g[], int source)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> distTo(n+1, INT_MAX);
    vector<int>shortestPath(n+1,0);
    distTo[source] = 0;
    shortestPath[source]=1;
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
            
            if(distTo[next] == distTo[prev] + nextDist)
            shortestPath[next]=shortestPath[next]+shortestPath[prev];

            if (distTo[next] > distTo[prev] + nextDist)
            {
                distTo[next] = distTo[prev] + nextDist;
                pq.push(make_pair(distTo[next], next));
                shortestPath[next]=shortestPath[prev];
            }
            
        }
    }

   for(int i=1;i<=n;i++) cout<<distTo[i]<<" ";
   cout<<"\n";
   for(int i=1;i<=n;i++) cout<<shortestPath[i]<<" ";
}

int main()
{
    int v = 9;
    vector<vector<int>> adj[v+1];

    addEdge(adj, 1, 2, 1);
    addEdge(adj, 2, 3, 1);
    addEdge(adj, 3, 4, 2);
    addEdge(adj, 4, 5, 1);
    addEdge(adj, 5, 6, 2);
    addEdge(adj, 6, 7, 2);
    addEdge(adj, 7, 8, 1);
    addEdge(adj, 8, 1, 1);
    addEdge(adj, 2, 8, 2);
    addEdge(adj, 3, 9, 1);
    addEdge(adj, 8, 9, 2);
    addEdge(adj, 7, 9, 2);
    addEdge(adj, 3, 6, 1);
    addEdge(adj, 4, 6, 1);

    dijkstra(v, adj, 1);

    return 0;
}
