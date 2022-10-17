/*
Given an unweighted directed graph, can be cyclic or acyclic. Print the number of shortest
 paths from a given vertex to each of the vertices. For example consider the below graph. 
 There is one shortest path vertex 0 to vertex 0 (from each vertex there is a single shortest path 
 to itself), one shortest path between vertex 0 to vertex 2 (0->2), and there are 4 different shortest
  paths from vertex 0 to vertex 6:

0->1->3->4->6
0->1->3->5->6
0->2->3->4->6
0->2->3->5->6

*/

#include <bits/stdc++.h>
using namespace std;

void BFS(vector<int> adj[], int src, int dist[],
         int paths[], int n)
{
    bool visited[n];
    for (int i = 0; i < n; i++)
        visited[i] = false;
    dist[src] = 0;
    paths[src] = 1;

    queue<int> q;
    q.push(src);
    visited[src] = true;
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        for (auto x : adj[curr])
        {

            if (visited[x] == false)
            {
                q.push(x);
                visited[x] = true;
            }

            // check if there is a better path.
            if (dist[x] > dist[curr] + 1)
            {
                dist[x] = dist[curr] + 1;
                paths[x] = paths[curr];
            }

            // additional shortest paths found
            else if (dist[x] == dist[curr] + 1)
                paths[x] += paths[curr];
        }
    }
}

void findShortestPaths(vector<int> adj[],
                       int s, int n)
{
    int dist[n], paths[n];
    for (int i = 0; i < n; i++)
        dist[i] = INT_MAX;
    for (int i = 0; i < n; i++)
        paths[i] = 0;
    BFS(adj, s, dist, paths, n);
    cout << "Numbers of shortest Paths are: ";
    for (int i = 0; i < n; i++)
        cout << paths[i] << " ";
}

void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}

int main()
{
    int n = 7;
    vector<int> adj[n];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    addEdge(adj, 3, 5);
    addEdge(adj, 4, 6);
    addEdge(adj, 5, 6);
    findShortestPaths(adj, 0, 7);
    return 0;
}
