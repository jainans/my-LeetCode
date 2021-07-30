class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
      int l=0;
      int r=0;
      int n=  nums.size();
        int ans= INT_MAX;
      int sum=0;
        
      while(sum<target && r<n){
          sum+=nums[r];
          r++;
      }
      while(l<=r && sum-nums[l]>=target){
          sum-=nums[l];
          l++;
      }
      if(sum>=target)
          ans = min(ans, r-l);
     else
         return 0;
     while(r<n){
         sum+=nums[r];
          while(l<=r && sum-nums[l]>=target){
          sum-=nums[l];
          l++;
      }
      ans = min(ans, r-l+1);
      r++;
     }
        return ans;
        
    }
};