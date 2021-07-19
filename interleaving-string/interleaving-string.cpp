class Solution {
public:
    int dp[202][101][101];
    int solve(int l, int p, int q, string s1, string s2, string s3){
        if(l==s3.size())
            return 1;
        if(dp[l][p][q]!=-1)
            return dp[l][p][q];
        if(p<s1.size() && q<s2.size() && s3[l]==s1[p] && s3[l]==s2[q]){
            return dp[l][p][q]= (solve(l+1, p+1, q, s1, s2, s3) || solve(l+1, p, q+1, s1, s2, s3));
        }
        else if(p<s1.size() && s3[l]==s1[p])
            return dp[l][p][q]= solve(l+1, p+1, q, s1, s2, s3);
        else if(q<s2.size() && s3[l]==s2[q])
            return dp[l][p][q]= solve(l+1, p, q+1, s1, s2, s3);
        
            return 0;
       
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s3.size()!=s1.size()+s2.size())
            return false;
        for(int i=0; i<=s3.size(); i++){
            for(int j=0; j<=s1.size(); j++){
                for(int k=0; k<=s2.size(); k++){
                    dp[i][j][k]=-1;
                }
            }
        }
        return solve(0, 0, 0, s1, s2, s3);
    }
};