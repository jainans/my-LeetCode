class Solution {
public:
    int dp[1002];
    int solve(int sum, vector<int>& nums){
        if(sum==0)
            return dp[sum]= 1;
        if(dp[sum]!=-1)
            return dp[sum];
        dp[sum]=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]<=sum)
                dp[sum]+=solve(sum-nums[i], nums);
        } 
        return dp[sum];
    }
    int combinationSum4(vector<int>& nums, int target) {
        for(int i=0; i<=target; i++)
            dp[i]=-1;
        return solve(target, nums);
    }
};