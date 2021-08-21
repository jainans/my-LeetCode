class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int mino = INT_MAX;

        bool bb = false;
        for(int i=1; i<n; i++){
            if(nums[i]<nums[i-1])
                bb=true;
            if(bb){
                if(mino>nums[i]){
                    mino=nums[i];
                }
            }
        }
        bb= false;
        int maxo = INT_MIN;
        for(int i=n-2; i>=0; i--){
            if(nums[i]>nums[i+1])
                bb= true;
            if(bb){
               maxo = max(maxo, nums[i]);
            }
        }
        int l=n+1;
        int r=-1;
        for(int i=0; i<n; i++){
            if(nums[i]>mino){
                l=i;
                break;
            }
        }
        for(int i=n-1; i>=0; i--){
            if(nums[i]<maxo){
                r = i;
                break;
            }
        }
        if(l<=r)
            return r-l+1;
        else
            return 0;
        
    }
};