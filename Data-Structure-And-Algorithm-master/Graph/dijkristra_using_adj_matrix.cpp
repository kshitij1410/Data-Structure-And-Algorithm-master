#include <iostream>
using namespace std;
#include <limits.h>

#define V 6


//O(V^2 )
int minDist(int dist[], bool sptSet[])
{

    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

void printSolution(int distance[])
{
    cout << "Vertex \t Distance from Source" << endl;
    for (int i = 0; i < V; i++)
        cout << (char)(i + 65) << " \t\t" << distance[i] << endl;
}

void dijkstra(int graph[V][V], int src)
{
    int distance[V];

    bool sptSet[V];

    for (int i = 0; i < V; i++)
        distance[i] = INT_MAX, sptSet[i] = false;

    distance[src] = 0;

    for (int count = 0; count < V - 1; count++)
    {

        int u = minDist(distance, sptSet);

        sptSet[u] = true;

        for (int v = 0; v < V; v++)
        {
            if (!sptSet[v] && graph[u][v] && distance[u] != INT_MAX && distance[u] + graph[u][v] < distance[v])
                distance[v] = distance[u] + graph[u][v];
        }

       
    }
     printSolution(distance);
}
    int main()
    {

        int graph[V][V] = {{0, 4, 5, 0, 0, 0},
                           {4, 0, 11, 9, 7, 0},
                           {5, 11, 0, 0, 3, 0},
                           {0, 9, 0, 0, 13, 2},
                           {0, 7, 3, 13, 0, 6},
                           {0, 0, 0, 2, 6, 0}};
        int source = 0;
        dijkstra(graph, source);

        return 0;
    }