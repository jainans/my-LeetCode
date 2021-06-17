class Solution {
public:
    int findDuplicate(vector<int>& nums) {
      //duplicates in an array will surely lead to the cycle in a linked list
      // so we will follow the cycle detection algo / Floyd's hare or tortoise algo to solve
        int hare = nums[0];
        int tor= nums[0];
        do{
            tor = nums[tor];
            hare = nums[nums[hare]];
        }while(hare != tor);
        tor=  nums[0];
        while(hare!=tor){
            hare= nums[hare];
            tor = nums[tor];
        }
        return tor;
    }
};
