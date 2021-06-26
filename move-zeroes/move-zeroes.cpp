class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int fstnz = 0;
            int p=0;
        while(fstnz<n){
        while(fstnz<n && nums[fstnz]==0)
            fstnz++;
            if(fstnz>=n)
                break;
            if(fstnz==p)
            {
                fstnz++;
                p++;
            }
            else{
            swap(nums[fstnz], nums[p]);
            p++;
            }
        }
    }
};