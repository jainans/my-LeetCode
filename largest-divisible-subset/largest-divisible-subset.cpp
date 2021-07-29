class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int>pre(n, -1);
        vector<int>dp(n, 1);
        for(int i=1; i<n; i++){
            for(int j=0; j<i; j++){
                if(nums[i]%nums[j]==0){
                    if(dp[j]+1>dp[i]){
                        dp[i]=dp[j]+1;
                        pre[i]=j;
                    }
                }
            }
        }
        int id=0;
        int maxo=dp[0];
        for(int i=0; i<n; i++){
            if(dp[i]>maxo){
                maxo=dp[i];
                id=i;
            }
            
        }
        vector<int>ans;
        while(id!=-1){
            ans.push_back(nums[id]);
            id = pre[id];
        }
        return ans;
    }
};