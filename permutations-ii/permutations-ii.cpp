class Solution {
public:
     void dfs(int id, vector<int>& nums, vector<int>temp, set<vector<int> >& ans){
         if(temp.size()==nums.size())
         {
             ans.insert(temp);
             return;
         }
         for(int i=id; i<nums.size(); i++){
            swap(nums[i], nums[id]);
             temp.push_back(nums[id]);
             dfs(id+1, nums, temp, ans);
             temp.pop_back();
             swap(nums[i], nums[id]);
         }
     }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
         sort(nums.begin(), nums.end());
       vector<int>temp;
        
        set<vector<int> >ans;
        dfs(0, nums, temp, ans);
        vector<vector<int> >st;
        for(auto itr = ans.begin(); itr!=ans.end(); ++itr)
            st.push_back(*itr);
        return st;
    }
};