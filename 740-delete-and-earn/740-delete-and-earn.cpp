class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int>mp;
        for(int i=0; i<n; i++){
            mp[nums[i]]++;
        }
        int dp[10001];
        dp[0]=0;
        dp[1]= mp[1];
        for(int i=2; i<=1e4; i++){
            dp[i]= i*mp[i]+dp[i-2];
            dp[i]=max(dp[i], dp[i-1]);
        }
        return dp[10000];
    }
};