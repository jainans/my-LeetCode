#define ll long long int
const ll mod= 1e9+7;
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        ll dp[n][n][2]; 
        // dp[i][j][0] stores minimum distance and dp[i][j][1] stores number of ways to reach     with the minimum distance dp[i][j][0]
        for(ll i=0; i<n; i++){
            for(ll j=0; j<n; j++){
                if(i!=j){
                    dp[i][j][0] = 1e13;
                    dp[i][j][1]=0;
                }
                else
                {
                    dp[i][j][0]=0;
                    dp[i][j][1]=1;
                }
            }
        }
        for(ll i=0; i<roads.size(); i++){
            dp[roads[i][0]][roads[i][1]][0]=roads[i][2];
            
            dp[roads[i][1]][roads[i][0]][0]=roads[i][2];
            dp[roads[i][0]][roads[i][1]][1]=1;
            
            dp[roads[i][1]][roads[i][0]][1]=1;
        }
        for(ll mid=0; mid<n; mid++){
            for(ll i=0; i<n; i++){
                for(ll j=0; j<n; j++){
                    if(i!=mid && j!=mid){
                        if(dp[i][mid][0]+dp[mid][j][0]<dp[i][j][0]){
                            dp[i][j][0]=dp[i][mid][0]+dp[mid][j][0];
                            dp[i][j][1] = (dp[i][mid][1]*dp[mid][j][1])%mod;
                        }
                        else if(dp[i][j][0]==dp[i][mid][0]+dp[mid][j][0]){
                            dp[i][j][1] = (dp[i][j][1]+dp[i][mid][1]*dp[mid][j][1])%mod;
                        }
                    }
                }
            }
        }
        return dp[n-1][0][1];
    }
};