class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m  = mat[0].size();
        vector<vector<int> >dp(n, vector<int>(m, 10001));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j]==0)
                    dp[i][j]=0;
                else{
                    if(i>0)
                        dp[i][j]=min(dp[i][j], 1+dp[i-1][j]);
                    if(j>0)
                        dp[i][j]=min(dp[i][j], 1+dp[i][j-1]);
                }
            }
        }
        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                if(mat[i][j]==0)
                    dp[i][j]=0;
                else{
                    if(i<n-1)
                        dp[i][j]=min(dp[i][j], 1+dp[i+1][j]);
                    if(j<m-1)
                        dp[i][j]=min(dp[i][j], 1+dp[i][j+1]);
                }
            }
        }
        return dp;
    }
};