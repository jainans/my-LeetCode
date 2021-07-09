class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum=0;
        for(int i=0; i<n; i++){
            sum+=nums[i];
        }
        int p = sum-target;
        if(p%2 || p<0)
            return 0;
        p/=2;
        // cout<<p<<endl;
        int dp[n+1][p+1];
      
        for(int i=0; i<=p; i++){
            dp[0][i]=0;
            if(i==0 )
                dp[0][i]=1;
        }
         
       
        for(int i=1; i<=n; i++){
            for(int j=0; j<=p; j++){
                if(j<nums[i-1])
                    dp[i][j]=dp[i-1][j];
                else
                    dp[i][j]=dp[i-1][j]+dp[i-1][j-nums[i-1]];
            }
        }
        return dp[n][p];
    }
};