class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int l=0;
        int mid=0;
        int r = n-1;
        while(mid<=r){
            if(nums[mid]==2){
                swap(nums[mid], nums[r]);
                r--;
            }
            else if(nums[mid]==1)
                mid++;
            else
            {
                swap(nums[mid], nums[l]);
                l++;
                mid++;
            }
        }
    }
};