class Solution {
public:
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        
        int n = mat[0].size();
        int m = mat.size();
        
        int dp[m+1][4905];
        
        memset(dp,0,sizeof dp);
        
        dp[0][0]=1;
        
        for(int i = 0;i<m;i++){
            
            for(int sum = 0;sum<=4900;sum++){
                
                if(dp[i][sum]==1){

                    for(auto el:mat[i]){
                        dp[i+1][sum+el]=true;   
                    }
                }   
            }
        }
        
        int ans = 90000;
        
        for(int sum = 0;sum<=4900;sum++){
            if(dp[m][sum]==true)
            ans = min(ans,abs(sum-target));
        }
        
        return ans;
    }
};