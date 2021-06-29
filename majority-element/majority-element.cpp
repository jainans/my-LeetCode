class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int curr=0;
        int cnt=1;
        for(int i=1; i<nums.size(); i++){
            if(nums[i]==nums[curr])
                cnt++;
            else{
                cnt--;
                if(cnt==0){
                    curr = i+1;
                    cnt=0;
                }
            }
        }
        return nums[curr];
    }
};