class Solution {
public:
    bool isMatch(string s, string p) {
         int n=  p.size();
        string t="";
        string chk="";
        for(int i=0; i<n; i++){
            if(p[i]!='*'){
                if((i+1)!=n && p[i+1]=='*')
                {
                    t+=p[i];
                    chk+='y';
                }
                else{
                    t+=p[i];
                    chk+='n';
                }
            }
        }
        n = s.size();
        int m = t.size();
        bool dp[n+1][m+1];
        dp[0][0]=true;
        for(int i=1; i<=n; i++){
            dp[i][0]=false;
        }
        for(int i=1; i<=m; i++){
            if(chk[i-1]=='y')
                dp[0][i] = dp[0][i-1];
            else
                dp[0][i]=false;
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(chk[j-1]=='y'){
                    if(s[i-1]==t[j-1] || t[j-1]=='.')
                        dp[i][j] = dp[i][j-1] | dp[i-1][j];
                    else
                        dp[i][j]=dp[i][j-1];
                }
                else{
                    if(s[i-1]==t[j-1] || t[j-1]=='.')
                        dp[i][j]=  dp[i-1][j-1];
                    else
                        dp[i][j]= false;
                }
            }
        }
        return dp[n][m];
    }
};