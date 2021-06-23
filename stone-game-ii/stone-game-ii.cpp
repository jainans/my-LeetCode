class Solution {
public:
    const static int N = 102;
    const static int M = 52;
    int dp[N][M];
    int solve(int st, int m, vector<int>& pref){
        if(st>=pref.size())
            return dp[st][m]=0;
        if(dp[st][m]!=-1)
            return dp[st][m];
        int y =(2*m<=pref.size()-st) ? 2*m : pref.size()-st;
        for(int x= 1; x<= y; x++){
            dp[st][m]=  max(dp[st][m], pref[pref.size()-1]-pref[st-1]-solve(st+x, max(m, x), pref));
        }
        return dp[st][m];
    }
    
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        for(int i=0; i<=n; i++){
            for(int j=0; j<=(n+1)/2; j++)
                dp[i][j]=-1;
        }
        vector<int>pref(n+1);
        pref[0]=0;
        for(int i=1; i<=n; i++){
            pref[i] =pref[i-1]+piles[i-1];
        }
        return solve(1, 1, pref);
    }
};