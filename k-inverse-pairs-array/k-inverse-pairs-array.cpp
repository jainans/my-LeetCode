#define ll long long int
const ll mod = 1e9+7;
class Solution {
public:
    int kInversePairs(int n, int k) {
        ll dp[n+1][k+1];
        for(ll i=0; i<=n; i++){
            for(ll j=0; j<=k; j++)
                dp[i][j]=0;
        }
       
            dp[1][0]=1;
         
        for(ll i=2; i<=n; i++){
            
            for(ll j = 0; j <= min(k*1LL, (i)*(i-1)/2); j++){
                
                dp[i][j]=dp[i-1][j];
                if(j-i>=0)
                    dp[i][j]= (dp[i][j]+dp[i][j-1]-dp[i-1][j-i]+mod)%mod;
                else if(j>0)
                    dp[i][j]=(dp[i][j]+dp[i][j-1])%mod;
                
                }
            }
        return dp[n][k];
    }
};