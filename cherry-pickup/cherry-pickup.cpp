class Solution {
public:
    
    int dp[51][51][51];
    int solve(int r1, int c1, int c2, int n, vector<vector<int> >& grid){
        int r2 = r1+c1-c2;
        if(r1==n || c1==n || c2==n || r2==n || grid[r1][c1]==-1 || grid[r2][c2]==-1)
            return -9999;
        if(r1==n-1 && c1==n-1){
            return dp[r1][c1][c2] =  grid[r1][c1];
        }
        if(dp[r1][c1][c2]!=INT_MIN)
            return dp[r1][c1][c2];
        int ans = grid[r1][c1];
        if(c1!=c2)ans+=grid[r2][c2];
        ans+=max({solve(r1+1, c1, c2, n, grid), solve(r1+1, c1, c2+1, n, grid), solve(r1, c1+1, c2, n, grid), solve(r1, c1+1, c2+1, n, grid)});
        dp[r1][c1][c2]=ans;
        return ans;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        //very very good problem
        //Two path sum with maximum ones from {0, 0} to {n-1, n-1}
        //Tricky to define dp state
        //Let's say one person starts at r1, c1 and second person starts at r2, c2
        //r1+c1==r2+c2 at a particular time
        int n = grid.size();
        for(int i=0; i<=n; i++){
            for(int j=0; j<=n; j++){
                for(int k=0; k<=n; k++)
                    dp[i][j][k]=INT_MIN;
            }
        }
        
        return max(0, solve(0, 0, 0, n, grid));
        
    }
};