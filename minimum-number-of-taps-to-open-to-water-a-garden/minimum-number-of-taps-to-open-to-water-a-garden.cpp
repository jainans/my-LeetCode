class Solution {
public:
    int minTaps(int n, vector<int>& num) {
      vector<int>dp(n+1, n+2);
        dp[0]=0;
        for(int i=0; i<=n; i++){
            for(int j=max(i-num[i], 0); j<=min(n, i+num[i]); j++)
                dp[j] = min(dp[j], 1+dp[max(i-num[i], 0)]);
        }
        return (dp[n]<n+2) ? dp[n] : -1;
    }
};