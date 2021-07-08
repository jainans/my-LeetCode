class Solution {
public:
    int dp[1001][1001];
   int dfs(int i, int j, string s){
        if(i==j){
           
           return dp[i][j]=1;
            
        }
       if(i==j-1){
           if(s[i]==s[j]){
               return dp[i][j]=1;
           }
           else
               return dp[i][j]=0;
       }
       if(dp[i][j]!=-1)
           return dp[i][j];
        if(s[i]!=s[j])
            return dp[i][j]=0;
        dp[i][j] = dfs(i+1, j-1, s);
       return dp[i][j];
       
            
    }
    int countSubstrings(string s) {
        int n=  s.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                dp[i][j]=-1;
            }
        }
        int ans=0;
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                ans+=dfs(i, j, s);
            }
        }
        return ans;
    }
};