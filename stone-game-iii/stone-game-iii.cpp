class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        int dp[n+1];
        dp[n]=0;
        dp[n-1] = stoneValue[n-1];
        if(n>=2)
            dp[n-2] = max(stoneValue[n-2]-dp[n-1], stoneValue[n-1]+stoneValue[n-2]-dp[n]);
        for(int i=n-3; i>=0; i--){
            dp[i] = max(stoneValue[i]-dp[i+1], max(stoneValue[i]+stoneValue[i+1]-dp[i+2], stoneValue[i]+stoneValue[i+1]+stoneValue[i+2]-dp[i+3]));
        }
        if(dp[0]>0)
            return "Alice";
        if(dp[0]==0)
            return "Tie";
        else
            return "Bob";
    }
};