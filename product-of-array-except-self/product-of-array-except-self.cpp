class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n);
        ans[n-1]=nums[n-1];
        for(int i=n-2; i>=0; i--){
            ans[i]=ans[i+1]*nums[i];
        }
        int pref=1;
        int temp;
        for(int i=0; i<n; i++){
            int suff = (i==n-1) ? 1 : ans[i+1];
           ans[i]=pref*suff;
            pref*=nums[i];
        }
        return ans;
    }
};