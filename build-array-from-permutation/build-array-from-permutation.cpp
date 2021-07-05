class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
       for(int i=0; i<nums.size(); i++){
          int p = nums[nums[i]] & 1023 ;
          nums[i] = (p<<10) + nums[i];
       }
    for(int i=0; i<nums.size(); i++){
        nums[i] = (nums[i]>>10);
    }
        return nums;
    }
};