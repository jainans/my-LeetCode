class Solution {
public:
    
    int dp2[2001][2001];
    int func(int l, int r, string s, vector<vector<int> >& dp){
        if(l>=r)
            return 0;
        if(dp2[l][r]!=-1)
            return dp2[l][r];
        if(dp[l][r]==1)
            return dp2[l][r]=0;
        dp2[l][r]=5000;
        for(int i=l; i<r; i++){
            if(dp[l][i]==1){
                dp2[l][r] = min(dp2[l][r], 1+func(i+1, r, s, dp));
            }
        }
        return dp2[l][r];
    }
    int minCut(string s) {
        int n = s.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                dp2[i][j]=-1;
            }
        }
        vector<vector<int> >dp(n, vector<int>(n, 0));
        for(int len=1; len<=n; len++){
            for(int i=0; i<=(n-len); i++){
                if(len==1)
                    dp[i][i+len-1]=1;
                else{
                    if(s[i]!=s[i+len-1])
                        dp[i][i+len-1]=0;
                    else{
                        if(len==2)
                           dp[i][i+len-1]=1;
                        else
                            dp[i][i+len-1]=dp[i+1][i+len-2];
                    }
                }
            }
        }
        return func(0, n-1, s, dp);
    }
};