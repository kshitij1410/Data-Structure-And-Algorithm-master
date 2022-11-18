








































Refresh

Time (IST)	Status	Lang	Test Cases	Code
2022-04-07 21:46:51	Correct	cpp	300 / 300	View
C++ (g++ 5.4)
Average Time:
15m
Your Time:
30m




Custom Input
public:
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    int x[]={-1,-1,-1,0,0,1,1,1};
	    int y[]={-1,0,1,-1,1,-1,0,1};
	    vector<vector<int>>ans;
	    
	    int len=word.size();
	    
	    int n=grid.size();
	    int m=grid[0].size();
	    
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<m;j++)
	        {
	            //check if the first char is matched
	            if(grid[i][j]==word[0])
	            {
	                for(int dir=0;dir<8;dir++)
	                {
	                    int xdir=i+x[dir];
	                    int ydir=j+y[dir];
	                    
	                    int ii=1;
	                    for( ii=1;ii<len;ii++)
	                    {
	                        if(xdir<0 or ydir<0 or xdir>=n or ydir>=m)
	                        break;
	                        if(grid[xdir][ydir]!=word[ii]) break;
	                        
	                        xdir+=x[dir];
	                        ydir+=y[dir];
	                    }
	                    
	                    if(ii==len)
	                    {
	                        ans.push_back({i,j});
	                        break;   
	                    }
	                }
	            }
	        }
	    }
	    return ans;
	}
};