class Solution {
public:
    void solve(int st, int n, vector<int>temp, vector<vector<int> >& ans, vector<int>& nums){
        if(st==n){
            ans.push_back(temp);
            return;
        }
        solve(st+1, n, temp, ans, nums);
        temp.push_back(nums[st]);
        solve(st+1, n, temp, ans, nums);
        temp.pop_back();
        return;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> >ans;
        vector<int>temp;
        solve(0, nums.size(), temp, ans, nums);
        return ans;
    }
};