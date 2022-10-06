//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initialColor = image[sr][sc];
        dfs(sr,sc,image,initialColor,color);
        return image;
    }
    private:
    void dfs(int i,int j,vector<vector<int>> &image,int initialColor,int color)
    {
        int n = image.size();
        int m = image[0].size();
        if(i<0 || i>=n || j<0 || j>=m || image[i][j] != initialColor || image[i][j] == color)
        {
            return;
        }
        image[i][j] = color;
        dfs(i,j+1,image,initialColor,color);
        dfs(i,j-1,image,initialColor,color);
        dfs(i-1,j,image,initialColor,color);
        dfs(i+1,j,image,initialColor,color);
    }
};


// } Driver Code Ends
class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int initialColor = image[sr][sc];
        if(image[sr][sc] == color)
        {
            return image;
        }
        queue<pair<int,int>> q;
        q.push({sr,sc});
        int dr[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};
        while(!q.empty())
        {
            int curi = q.front().first;
            int curj = q.front().second;
            q.pop();
            if(image[curi][curj] != initialColor)
            {
                continue;
            }
            image[curi][curj] = color;
            for(int i=0;i<4;i++)
            {
                int dx = dr[i][0];
                int dy = dr[i][1];
                int nbri = curi+dx;
                int nbrj = curj+dy;
                if(nbri>=0 && nbri<n && nbrj>=0 && nbrj<m && image[nbri][nbrj] == initialColor)
                {
                    q.push({nbri,nbrj});
                }
            }
        }
        return image;
    
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends