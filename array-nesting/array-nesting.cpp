class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        //same question as minimum swaps required to sort a permutation
        
        int ans=0;
        int n = nums.size();
        for(int i=0; i<n; i++){
            int p=1;
            for(int j=nums[i]; j!=i; j=nums[i]){
                swap(nums[i], nums[j]);
                p++;
            }
            ans = max(ans, p);
        }
        return ans;
    }
};