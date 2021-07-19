class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
      int n = nums.size();
      vector<int>pref(n+1, 0);
      for(int i=0; i<n; i++){
          pref[i+1] = pref[i]+nums[i];
      }
        vector<int>dp(n);
       for(int i=0; i<n; i++)
           dp[i]=nums[i];
      for(int l=n-2; l>=0; l--){
          for(int r = l+1; r<n; r++){
              dp[r] = max(pref[r+1]-pref[l+1]-dp[r]+nums[l], pref[r]-pref[l]-dp[r-1]+nums[r]);
          }
      }
      if(dp[n-1]>=(pref[n]+1)/2)
          return true;
        return false;
    }
};