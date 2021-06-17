class Solution {
public:
    const static int N = 203;
    int dp[N][N];
    int solve(vector<vector<int>>& a, int& n, int& m, int i, int j){
        int l = (j>0 && a[i][j-1]<a[i][j]) ? 1 : 0; 
        int r = (j<m-1 && a[i][j+1]<a[i][j]) ? 1 : 0;
        int u = (i>0 && a[i-1][j]<a[i][j]) ? 1 : 0;
        int d = (i<n-1 && a[i+1][j]<a[i][j]) ? 1 : 0;
        
        if(l==0 && r==0 && u==0 && d==0)
            return dp[i][j]=1;
        if(dp[i][j]!=-1)
            return dp[i][j];
        dp[i][j]=1;
        if(l==1)
            dp[i][j] = max(dp[i][j], 1+solve(a, n, m, i, j-1));
        if(r==1)
            dp[i][j] = max(dp[i][j], 1+solve(a, n, m, i, j+1));
        if(u==1)
            dp[i][j] = max(dp[i][j], 1+solve(a, n, m, i-1, j));
        if(d==1)
            dp[i][j] = max(dp[i][j], 1+solve(a, n, m, i+1, j));
        return dp[i][j];
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n  = matrix.size();
        int m  = matrix[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                dp[i][j]=-1;
            }
        }
        int ans=0;
           for(int i=0; i<n; i++){
               for(int j=0; j<m; j++){
                   ans = max(ans, solve(matrix, n, m, i, j));
               }
           } 
        return ans;
    }
};