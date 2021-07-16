class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=  nums.size();
        vector<vector<int> >ans;
        if(n<3)
            return ans;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n-2; i++){
            if(i>0 && nums[i]==nums[i-1])continue;
            int l=i+1;
            int r = n-1;
            while(l<r){
                if(nums[i]+nums[l]+nums[r]==0){
                    ans.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                    while(l<r && nums[l]==nums[l-1])
                        l++;
                    while(r>l && nums[r]==nums[r+1])
                        r--;
                }
                else if(nums[i]+nums[l]+nums[r]>0){
                    r--;
                }
                else{
                    l++;
                }
            }
        }
        return ans;
    }
};