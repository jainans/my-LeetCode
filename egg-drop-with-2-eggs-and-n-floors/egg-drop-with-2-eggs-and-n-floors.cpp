class Solution {
public:
    static const int N = 1002;
    int dp[N];
    int twoEggDrop(int n) {
        if(n<=2)
            return n;
        if(dp[n]!=0)
            return dp[n];
        int ans = INT_MAX;
        for(int i=1; i<=n; i++){
            ans = min(ans, max(i, 1+twoEggDrop(n-i)));
        }
        return dp[n]= ans;
        
    }
};