class Solution {
public:
// recursive soution 
    int sove(vector<int>coins,int amount,int n )
    {
        if(n==0 and amount!=0) return INT_MAX;
        if(amount==0) return 0;
        
        
        //don't pick
        int a =sove(coins,amount,n-1);
        
        // pick
        if(amount>=coins[n-1])
        a=min(a,sove(coins,amount-coins[n-1],n)==INT_MAX?INT_MAX:sove(coins,amount-coins[n-1],n)+1);
        
        return a;
        
    }

    //tabuation 
    int coinChange(vector<int>& coins, int amount) {
       int n=coins.size();
        
        // return sove(coins,amount,n)==INT_MAX?-1:sove(coins,amount,n); 
        int dp[n+1][amount+1];
        for(int i=0;i<=amount;i++) dp[0][i]=INT_MAX;
        for(int i=0;i<=n;i++) dp[i][0]=0;
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=amount;j++)
            {
                //don't pick
                dp[i][j]=dp[i-1][j];
                
                //pick
                if(j>=coins[i-1])
                {
                    int temp=dp[i][j-coins[i-1]];
                    if(temp==INT_MAX)
                        dp[i][j]=min(dp[i][j],temp);
                    else
                        dp[i][j]=min(dp[i][j],temp+1);
                }
            }
        }
        
        return dp[n][amount]==INT_MAX?-1:dp[n][amount];
    }
};

//space optimization

 int coinChange(vector<int>& coins, int amount) {
       int n=coins.size();
        
        vector<int>prev(amount+1,0),curr(amount+1,0);
        for(int i=1;i<=amount;i++) prev[i]=INT_MAX;
         
        
        for(int i=1;i<=n;i++)
        {
            curr[0]=0;
            for(int j=1;j<=amount;j++)
            {
                //don't pick
               curr[j]=prev[j];
                
                //pick
                if(j>=coins[i-1])
                {
                    int temp=curr[j-coins[i-1]];
                    if(temp==INT_MAX)
                        curr[j]=min(curr[j],temp);
                    else
                        curr[j]=min(curr[j],temp+1);
                }
            }
            prev=curr;
        }
        
        return prev[amount]==INT_MAX?-1:prev[amount];
    }