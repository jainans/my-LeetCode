const int N = 501;
int dp[N][N];

int solve(int l, int r, vector<int>& stone){
    if(l==r)
        return dp[l][r]=0;
    if(dp[l][r]!=-1)
        return dp[l][r];
    int sum=0;
    for(int t=l; t<=r; t++){
        sum+=stone[t];
    }
    int p=0;
    dp[l][r]=0;
    for(int t=l; t<r; t++){
        p+=stone[t];
        sum-=stone[t];
        if(p<sum)
            dp[l][r]=max(dp[l][r], p+solve(l, t, stone));
        else if(sum<p)
            dp[l][r]=max(dp[l][r], sum+solve(t+1, r, stone));
        else
            dp[l][r]=  max(dp[l][r], p+max(solve(l, t, stone), solve(t+1, r, stone)));
    }
    return dp[l][r];
}
class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int n=  stoneValue.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++)
                dp[i][j]=-1;
        }
        return solve(0, n-1, stoneValue);
    }
};