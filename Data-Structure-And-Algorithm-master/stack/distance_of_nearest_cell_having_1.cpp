//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
    
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    queue<pair<pair<int,int>,int> >q;
	    int n=grid.size();
	    int m=grid[0].size();
	    
	    
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<m;j++)
	        {
	            if(grid[i][j]==1)
	            q.push({ {i,j},0});
	        }
	    }
	    vector<vector<int>>dis(n,vector<int>(m,0));
	     vector<vector<int>>vis(n,vector<int>(m,0));
	     
	    int derow[]={-1,0,0,1};
	    int deco[]={0,-1,1,0};
	    
	    while(!q.empty())
	    {
	        int row=q.front().first.first;
	        int co=q.front().first.second;
	        int steps=q.front().second;
	        q.pop();
	        vis[row][co]=1;
	        dis[row][co]=steps;
	        
	        for(int i=0;i<4;i++)
	        {
	            int r=derow[i]+row;
	            int c=deco[i]+co;
	            if(r>=0 and r<n and c>=0 and c<m)
	            {
	                 if(vis[r][c]==0 and grid[r][c]==0)
	                {
	                  vis[r][c]=1;
	                  q.push({ {r,c},steps+1});
	                }
	           
	            }
	            
	        }
	        
	    }
	    
	    return dis;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends