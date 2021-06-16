class Solution {
public:
    bool divisorGame(int n) {
        if(n==1)
            return false;
        if(n==2)
            return true;
        bool dp[n+1];
        dp[1]=false;
        dp[2]=true;
        for(int i=3; i<=n; i++){
            dp[i]=false;
            for(int j=1; j<i; j++){
                if(i%j==0 && dp[i-j]==false)
                    dp[i]=true;
                    
            }
        }
        return dp[n];
    }
};