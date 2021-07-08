class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k = k%n;
        if(k==0)
            return;
        //youu know how to reverse an array in place 
        //use that fact
        //reverse whole array
        //reverse first k elements
        //reverse last n-k elements
        //you motherfucker 
        //dimag laga lo thoda bc
        int l=0;
        int r = n-1;
        while(l<r){
            swap(nums[l], nums[r]);
            l++;
            r--;
        }
        l=0;
        r=k-1;
        while(l<r){
            swap(nums[l], nums[r]);
            l++;
            r--;
        }
        l=k;
        r = n-1;
        while(l<r){
            swap(nums[l], nums[r]);
            l++;
            r--;
        }
    }
};