
class Solution{
public:
    int nCr(int n, int k){
        
        if(k>n) return 0;
        if(k==n) return 1;
       int C[n + 1][k + 1];
    int i, j;
    int mod=1e9+7;
 
    // Calculate value of Binomial Coefficient
    // in bottom up manner
    for (i = 0; i <= n; i++) {
        for (j = 0; j <= min(i, k); j++) {
            // Base Cases
            if (j == 0 || j == i)
                C[i][j] = 1*1LL;
 
            // Calculate value using previously
            // stored values
            else
                C[i][j] = ((C[i - 1][j - 1]*1LL) %mod+ (C[i - 1][j]*1LL)%mod)%mod;
        }
    }
 
    return C[n][k];
    }
};