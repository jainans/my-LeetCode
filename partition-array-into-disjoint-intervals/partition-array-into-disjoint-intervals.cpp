class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        // so the main idea is that we will keep track of so far max variable
        /// if curr element is smaller than so far max than it will be in left part surely 
        //so we'll update our answer to be that curr+1;
        int maxo = nums[0];
        int tt=nums[0];
        int id=1;
        for(int i=1; i<nums.size(); i++){
            if(nums[i]<tt){
                id = i+1;
                tt = maxo;
            }
            maxo = max(maxo, nums[i]);
        }
        return id;
    }
};