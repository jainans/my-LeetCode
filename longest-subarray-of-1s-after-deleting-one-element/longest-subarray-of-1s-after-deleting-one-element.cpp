class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int prev=-1;
        int pre =-1;
        int i=0;
        int ans=0;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(nums[i]==0){
                ans = max(ans, i-1-prev);
                prev = pre;
                pre= i;
            }
        }
        ans = max(ans, n-1-prev);
        return ans-1;
    }
};