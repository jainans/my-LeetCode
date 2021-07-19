#define ll long long int
class Solution {
public:
    int numDistinct(string s, string t) {
        ll mod = 1e9+7;
        ll n = t.size();
        ll m = s.size();
        ll dp[n][m];
        if(s[0]==t[0])
            dp[0][0]=1;
        else
            dp[0][0]=0;
        for(ll i=1; i<m; i++){
            if(s[i]==t[0])
                dp[0][i]=dp[0][i-1]+1;
            else
                dp[0][i]=dp[0][i-1];
        }
        for(ll i=1; i<n; i++){
            for(ll j=0; j<m; j++){
                if(j<i)
                    dp[i][j]=0;
                else{
                   if(t[i]==s[j]){
                      dp[i][j] = (dp[i-1][j-1]+dp[i][j-1])%mod;
                   }
                   else
                       dp[i][j] = dp[i][j-1];
                
                }
            }
        }
        return dp[n-1][m-1];
    }
};