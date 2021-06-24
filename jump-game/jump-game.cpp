class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()==1)
            return true;
        nums[nums.size()-1]=1;
        for(int i=nums.size()-2; i>=0; i--){
            if(nums[i]==0)
                nums[i]=nums[i+1];
            else if(i+nums[i]>=nums.size()-1)
                nums[i] = nums[i+1]+1;
            else{
                if(nums[i+1]-nums[i+nums[i]+1]>0)
                    nums[i]=nums[i+1]+1;
                else
                    nums[i]=nums[i+1];
            }
        }
        return (nums[0]>nums[1]);
    }
};