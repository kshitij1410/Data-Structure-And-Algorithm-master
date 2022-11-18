/*
There are n cities connected by some number of flights. You are given an array
flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city
fromi to city toi with cost pricei.

You are also given three integers src, dst, and k, return the cheapest
price from src to dst with at most k stops. If there is no such route, return -1.
*/

// Correct solution
class Solution
{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
    {
        vector<pair<int, int>> adj[n];
        vector<int> dis(n, 1e9);
        queue<vector<int>> q;

        for (auto it : flights)
        {
            adj[it[0]].push_back({it[1], it[2]});
        }

        q.push({0, src, 0});
        dis[src] = 0;

        while (!q.empty())
        {

            int stop = q.front()[0];
            int node = q.front()[1];
            int cost = q.front()[2];
            q.pop();
            if (stop > k)
                continue;
            for (auto it : adj[node])
            {
                int adjNode = it.first;
                int weight = it.second;

                if (cost + weight < dis[adjNode])
                {
                    dis[adjNode] = cost + weight;
                    q.push({stop + 1, adjNode, cost + weight});
                }
            }
        }

        return dis[dst] == 1e9 ? -1 : dis[dst];
    }
};

// got tle in leetcode----------------------------------------------

// struct cmp
// {
//   bool operator()(pair<pair<int,int>,int>&a,pair<pair<int,int>,int>&b)
//   {
//       return a.first.first>b.first.first;
//   }
// };

// class Solution {
//   public:
//     int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int k)  {
//         // priority_queue<pair<pair<int,int>,int>,vector<pair<pair<int,int>,int>>,cmp>pq;
//        queue<pair<pair<int,int>,int>>pq;
//        vector<pair<int,int>>adj[n];
//        for(int i=0;i<flights.size();i++)
//        {
//           int u=flights[i][0];
//           int v=flights[i][1];
//           int price=flights[i][2];
//           adj[u].push_back({v,price});
//        }

//       pq.push( {{0,src},k});
//       int ans=INT_MAX;

//       while(!pq.empty())
//       {
//           int node=pq.front().first.second;
//           int nodePrice=pq.front().first.first;
//           int _k=pq.front().second;
//           pq.pop();
//           if(_k<0) continue;
//           if(ans<nodePrice) continue;

//           for(auto nbr: adj[node])
//           {
//               int nbrNode=nbr.first;
//               int nbrPrice=nbr.second;
//               if(dst==nbrNode)
//               {
//                   ans=min(ans,nbrPrice+nodePrice);
//               }
//               else{
//                   pq.push({{nbrPrice+nodePrice,nbrNode},_k-1});
//               }
//           }
//       }
//      if(ans==INT_MAX) return -1;

//     return ans;
//     }
// };