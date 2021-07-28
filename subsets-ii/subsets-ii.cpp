class Solution {
public:
    void solve(int id, vector<int>& nums, vector<int>temp, set<vector<int> >& ans){
        if(id==nums.size()){
            ans.insert(temp);
            return;
        }
        temp.push_back(nums[id]);
        solve(id+1, nums, temp, ans);
        temp.pop_back();
        solve(id+1, nums, temp, ans);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>temp;
        set<vector<int> >ans;
        sort(nums.begin(), nums.end());
        solve(0, nums, temp, ans);
        vector<vector<int> >st;
        for(auto it=ans.begin(); it!=ans.end(); ++it){
            st.push_back(*it);
        }
        return st;
    }
};