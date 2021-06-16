class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n  =nums.size();
        if(n<3)
            return false;
        int f = nums[0];
        int s = INT_MAX;
        int t = INT_MAX;
        for(int i=0; i<n; i++){
            if(nums[i]>s)
                return true;
            if(nums[i]>f)
                s = nums[i];
            else
                f = nums[i];
        }
        return false;
    }
};