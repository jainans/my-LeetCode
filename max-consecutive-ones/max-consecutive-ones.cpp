class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int num=0;
        int nas=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==0){
                nas = max(nas, num);
                num=0;
            }
            else
                num++;
        }
        nas = max(nas, num);
        return nas;
    }
};