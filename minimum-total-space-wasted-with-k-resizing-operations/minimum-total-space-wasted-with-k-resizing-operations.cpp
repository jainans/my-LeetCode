class Solution {
public:
    int minSpaceWastedKResizing(vector<int>& nums, int k) {
        //dp approach 
        // p resizing done before ith index
        // == p-1 resizing done before i-1, i-2, ... p-1th index
        int n=  nums.size();
        int dp[n][k+1];
       
        int sum=0;
        int maxo = INT_MIN;
        for(int i=0; i<n; i++){
            sum+=nums[i];
            maxo = max(maxo, nums[i]);
            dp[i][0]=(i+1)*maxo-sum;
        }
        for(int i=0; i<n; i++){
            for(int j=1; j<=k; j++){
                dp[i][j]=INT_MAX;
                int sm = nums[i];
                int mx = nums[i];
                int nm=1;
                for(int x=i-1; x>=j-1; x--){
                    dp[i][j]=  min(dp[i][j], dp[x][j-1]+nm*mx-sm);
                    sm+=nums[x];
                    nm++;
                    mx=  max(mx, nums[x]);
                }
            }
        }
        int ans=INT_MAX;
        for(int i=0; i<=k; i++){
            ans = min(ans, dp[n-1][i]);
        }
        
        return ans;
     
    }
};