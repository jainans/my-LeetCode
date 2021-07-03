class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m =  matrix[0].size();
        int dp[n][m];
        int dp2[n][m];
        int maxo=0;
        for(int i=0; i<n; i++){
            dp[i][0]=(matrix[i][0]=='1') ? 1 : 0;
            maxo = max(maxo, dp[i][0]);
        }
        for(int j=0; j<m; j++){
            dp[0][j]=(matrix[0][j]=='1') ? 1 : 0;
            maxo = max(maxo, dp[0][j]);
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(j==0){
                    if(matrix[i][j]=='1')
                        dp2[i][j]=1;
                    else
                        dp2[i][j]=0;
                }
                else{
                    if(matrix[i][j]=='0')
                        dp2[i][j]=0;
                    else
                        dp2[i][j]= dp2[i][j-1]+1;
                }
            }
        }
     
        for(int j=0; j<m; j++){
            int p = (matrix[0][j]=='1') ? 1 : 0;
            for(int i=0; i<n; i++){
                if(i==0){
                    if(p<dp2[i][j])
                        dp2[i][j]=p;
                }
                else{
                    if(matrix[i][j]=='0')
                        p=0;
                    else
                        p+=1;
                    if(p<dp2[i][j])
                        dp2[i][j]=p;
                }
            }
        }
       
        for(int i=1; i<n; i++){
            for(int j=1; j<m; j++){
                dp[i][j]= min(dp[i-1][j-1]+1, dp2[i][j]);
                maxo = max(maxo, dp[i][j]);
            }
        }
        
        return maxo*maxo;
    }
};