class Solution {
public:
    void rev(int l, int r, vector<int>& nums){
        int temp;
        while(l<r){
            temp = nums[l];
            nums[l]=nums[r];
            nums[r]=temp;
            l++;
            r--;
        }
    }
    void nextPermutation(vector<int>& nums) {
        int n= nums.size();
        if(n==1)
            return;
        int id=-1;
        for(int i=0; i<n-1; i++){
            if(nums[i]<nums[i+1])
                id=i;
        }
        
        
        if(id==-1){
            rev(0, n-1, nums);
        }
        else{
            int pid;
            for(int i=id+1; i<n; i++){
                if(nums[i]>nums[id])
                    pid=i;
            }
            int temp = nums[id];
            nums[id]  = nums[pid];
            nums[pid]=temp;
            rev(id+1, n-1, nums);
        }
    }
};