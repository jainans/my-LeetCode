class Solution {
public:
    int ans=0;
    void solve(int id, vector<int>& nums, int temp){
        if(id==nums.size()){
            ans+=temp;
            return;
        }
        solve(id+1, nums, temp);
        temp = temp^nums[id];
        solve(id+1, nums, temp);
        temp = temp^nums[id];
    }
    int subsetXORSum(vector<int>& nums) {
        ans=0;
        solve(0, nums, 0);
        return ans;
    }
};