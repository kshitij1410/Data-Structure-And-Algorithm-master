//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    int result=0;

    // issue with this approach when [     0,1,2
                                        // 0,1,2
                                        // 2,1,1]

    // acutal output is 1 but when we use matrix approach that give 3 as a output.
    // so we have to use bfs approach 
                                        
    //Function to find minimum time required to rot all oranges.
    // void solve(vector<vector<int>>& grid ,int r,int c,int n,int m)
    // {
    //     int flag=0;
        
    //     int row[4]={-1,0,0,1};
    //     int col[4]={0,-1,1,0};
        
    //     for(int i=0;i<4;i++)
    //     {
    //         //corner case
    //         int _row=row[i]+r;
    //         int _col=col[i]+c;
            
    //         if(_row>=0 and _row<n and _col>=0 and _col<m and grid[_row][_col]==1)
    //         {
    //             grid[_row][_col]=2;
    //             flag=1;
    //         }
    //     }
    //     if(flag==1) result++;
        
    // }
    
    int orangesRotting(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        int cnt=0;
       
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1) cnt++;
                if(grid[i][j]==2)
                {
                    q.push({i,j});
                    
                }
            }
        }
        
        
        int row[4]={-1,0,0,1};
        int col[4]={0,-1,1,0};
        
        // bfs algo
        
        while(!q.empty())
        {
            int size = q.size();
            int flag=0;
            
            while(size--)
            {
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                
                for(int i=0;i<4;i++)
                {
                   //corner case
                   int _row=row[i]+r;
                   int _col=col[i]+c;
            
                   if(_row>=0 and _row<n and _col>=0 and _col<m and grid[_row][_col]==1)
                    {
                     grid[_row][_col]=2;
                     q.push({_row,_col});
                     flag=1;
                     cnt--;
                    }
                }
                
            }
            
            if(flag==1) result++;
        }
        
        // int ans=0;
        
        // for(int i=0;i<n;i++)
        // {
        //     for(int j=0;j<m;j++)
        //     {
        //         if(grid[i][j]==1)
        //         ans++;
        //     }
        // }
        
        // return ans==0? result:-1;
        
        return cnt==0? result:-1;
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
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends