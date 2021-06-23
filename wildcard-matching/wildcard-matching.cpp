class Solution {
public:
    
    bool isMatch(string s, string p) {
      //bottom-up dp table
        string t = "";
        for(int i=0; i<p.size(); i++){
            if(i==0)
                t+=p[0];
            else{
                if(p[i]=='*' && p[i-1]=='*')
                    continue;
                else
                    t+=p[i];
            }
        }
        int n = s.size();
        if(s.size()==0){
            if(t.size()==0 || (t.size()==1 && t[0]=='*'))
                return true;
            return false;
        }
        bool dp[2][t.size()+1];
        dp[0][0]=true;
        for(int i=1; i<=t.size(); i++){
            if(t[i-1]=='*')
                dp[0][i]=dp[0][i-1];
            else
                dp[0][i]=false;
        }
        for(int i=0; i<s.size(); i++){
            if(i%2==0){
                dp[1][0]=false;
                for(int j=1; j<=t.size(); j++){
                    if(t[j-1]=='?' || t[j-1]==s[i])
                        dp[1][j] = dp[0][j-1];
                    else if(t[j-1]=='*')
                        dp[1][j] = dp[1][j-1] | dp[0][j];
                    else
                        dp[1][j]=false;
                }
            }
            else{
                 dp[0][0]=false;
                for(int j=1; j<=t.size(); j++){
                    if(t[j-1]=='?' || t[j-1]==s[i])
                        dp[0][j] = dp[1][j-1];
                    else if(t[j-1]=='*')
                        dp[0][j] = dp[0][j-1] | dp[1][j];
                    else
                        dp[0][j]=false;
                }
            }
        }
        return dp[n%2][t.size()];
        
    }
};