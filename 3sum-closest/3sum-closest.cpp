class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 1000006;
        for(int i=0; i<n-2; i++){
            int y = target-nums[i];
            int l=i+1;
            int r =  n-1;
            while(l<r){
                if(nums[l]+nums[r]==y){
                    ans = target;
                    break;
                }
                else if(nums[l]+nums[r]<y){
                   if(abs(nums[i]+nums[l]+nums[r]-target)<abs(ans-target))
                       ans= nums[i]+nums[l]+nums[r];
                    l++;
                }
                else{
                    if(abs(nums[i]+nums[l]+nums[r]-target)<abs(ans-target))
                       ans= nums[i]+nums[l]+nums[r];
                    r--;
                }
            }
        }
        return ans;
    }
};