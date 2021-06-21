class Solution {
public:
     
    int maxCoins(vector<int>& nums) {
       //the idea is to think in reverse order.
        //we will take ith ballon as last ballon to burst
        //in this way we will have clear cut boundaries for left and right subarrays
        
        int n=  nums.size();
        int dp[n][n][2];
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++){
                dp[i][j][0]=0;
                dp[i][j][1]=i;
            }
        }
        for(int i=0; i<n; i++){
            dp[i][i][1]=i;
            int lef=(i==0) ? 1 : nums[i-1];
            int rit = (i==n-1) ? 1 :nums[i+1];
            dp[i][i][0]=nums[i]*lef*rit;
        }
        for(int len=2; len<=n; len++){
            for(int i=0; i<n-len+1; i++){
                dp[i][i+len-1][0] = 0;
                for(int last=i; last<i+len; last++){
                    int lef = (i==0) ? 1 : nums[i-1];
                    int rit = (i+len-1==n-1) ? 1 : nums[i+len];
                    int dplef = (last==i) ? 0 : dp[i][last-1][0];
                    int dprit = (last==i+len-1) ? 0 : dp[last+1][i+len-1][0];
                    if(lef*rit*nums[last]+dplef+dprit > dp[i][i+len-1][0]){
                        dp[i][i+len-1][0]=lef*rit*nums[last]+dplef+dprit;
                        dp[i][i+len-1][1] = last;
                    }
                }
            }
        }
        
        
        
        
        return dp[0][n-1][0];
    }
};