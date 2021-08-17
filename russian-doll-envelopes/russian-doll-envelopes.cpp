class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end());
        int n = envelopes.size();
        int dp[n];
        int ans=1;
        dp[0]=1;
        for(int i=1; i<n; i++){
            dp[i]=1;
            for(int j=0; j<i; j++){
                if(envelopes[j][0]<envelopes[i][0] && envelopes[j][1]<envelopes[i][1])
                    dp[i]=  max(dp[i], 1+dp[j]);
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};