#define ll long long int
class Solution {
public:
    ll dp[5001][10];
    
    int knightDialer(int n) {
        if(n==1)
            return 10;
        ll mod = 1e9+7;
        for(int i=0; i<10; i++){
            dp[1][i]=1;
        }
        for(ll i=2; i<=n; i++){
            dp[i][0] = (dp[i-1][6]+dp[i-1][4])%mod;
            dp[i][1] = (dp[i-1][6]+dp[i-1][8])%mod;
            dp[i][2] = (dp[i-1][7]+dp[i-1][9])%mod;
            dp[i][3] = (dp[i-1][4]+dp[i-1][8])%mod;
            dp[i][4] = (dp[i-1][0]+dp[i-1][3]+dp[i-1][9])%mod;
            dp[i][5] = 0;
            dp[i][6] = (dp[i-1][0]+dp[i-1][1]+dp[i-1][7])%mod;
            dp[i][7] = (dp[i-1][6]+dp[i-1][2])%mod;
            dp[i][8] = (dp[i-1][1]+dp[i-1][3])%mod;
            dp[i][9] = (dp[i-1][4]+dp[i-1][2])%mod;
        }
        int ans=0;
        for(int i=0; i<10; i++){
            ans = (ans+dp[n][i])%mod;
        }
        return ans;
    }
};