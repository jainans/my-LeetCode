class Solution {
public:
    int dp[30][30][30][30];
    int solve(string &s1, string &s2, int l1, int r1, int l2, int r2){
        if(r1==l1){
            if(s1[l1]==s2[l2])
                return dp[l1][r1][l2][r2]=1;
             return dp[l1][r1][l2][r2]=0;
        }
        if(dp[l1][r1][l2][r2]!=-1)
            return dp[l1][r1][l2][r2];
        for(int i=l1; i<r1; i++){
           bool ans= (solve(s1, s2, l1, i, l2, l2+i-l1) & solve(s1, s2, i+1, r1, l2+i-l1+1, r2));
            bool rt= (solve(s1, s2, i+1, r1, l2, l2+r1-i-1) & solve(s1, s2, l1, i, l2+r1-i, r2));
           bool p = ans | rt;
            if(p)
                return dp[l1][r1][l2][r2]= 1;
            
        }
        return dp[l1][r1][l2][r2]=0;
    }
    bool isScramble(string s1, string s2) {
        memset(dp, -1, sizeof(dp));
        return solve(s1, s2, 0, s1.size()-1, 0, s2.size()-1);
    }
};