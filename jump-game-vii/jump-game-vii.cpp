class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        vector<int>dp(n);
        dp[0]=1;
        if(s[n-1]=='1')
            return false;
        for(int i=1; i<n; i++){
            if(s[i]=='1')
                dp[i]=dp[i-1];
            else{
                int p = i-minJump;
                int q = i-maxJump-1;
                int r=(q>=0) ? dp[q] : 0;
                if(p>=0 && dp[p]-r>0)
                    dp[i]=dp[i-1]+1;
                else
                    dp[i]=dp[i-1];
            }
        }
        return (dp[n-1]!=dp[n-2]);
    }
};