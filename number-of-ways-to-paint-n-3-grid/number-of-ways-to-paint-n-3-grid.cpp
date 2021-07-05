#define ll long long int 
class Solution {
public:
    ll dp[5000][13];
    int numOfWays(int n) {
        for(ll i=1; i<=12; i++){
            dp[0][i]=1;
        }
        ll mod = 1e9+7;
        for(ll i=1; i<n; i++){
           
                dp[i][1] = (dp[i-1][5]+dp[i-1][6]+dp[i-1][8]+dp[i-1][9]+dp[i-1][10])%mod;
                dp[i][2] = (dp[i-1][5]+dp[i-1][7]+dp[i-1][8]+dp[i-1][9])%mod;
                dp[i][3] = (dp[i-1][5]+dp[i-1][6]+dp[i-1][12]+dp[i-1][9]+dp[i-1][10])%mod;
                dp[i][4] = (dp[i-1][11]+dp[i-1][6]+dp[i-1][12]+dp[i-1][10])%mod;
               dp[i][5] = (dp[i-1][1]+dp[i-1][2]+dp[i-1][3]+dp[i-1][11]+dp[i-1][12])%mod;
               dp[i][6] = (dp[i-1][1]+dp[i-1][3]+dp[i-1][4]+dp[i-1][11])%mod;
                dp[i][7] = (dp[i-1][2]+dp[i-1][10]+dp[i-1][12]+dp[i-1][9])%mod;
                dp[i][8] = (dp[i-1][1]+dp[i-1][2]+dp[i-1][12]+dp[i-1][11]+dp[i-1][10])%mod;
                dp[i][9] = (dp[i-1][1]+dp[i-1][2]+dp[i-1][3]+dp[i-1][7])%mod;
               dp[i][10] = (dp[i-1][1]+dp[i-1][4]+dp[i-1][3]+dp[i-1][7]+dp[i-1][8])%mod;
              dp[i][11] = (dp[i-1][4]+dp[i-1][6]+dp[i-1][5]+dp[i-1][8])%mod;
               dp[i][12] = (dp[i-1][4]+dp[i-1][5]+dp[i-1][3]+dp[i-1][7]+dp[i-1][8])%mod;
        }
        int nas=0;
        for(int i=1; i<=12; i++){
            nas = (nas+dp[n-1][i])%mod;
        }
        return nas;
    }
};