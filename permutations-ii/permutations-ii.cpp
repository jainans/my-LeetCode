class Solution {
public:
     void dfs(vector<int>& nums, vector<int>temp, set<vector<int> >& ans, vector<int>& vis){
         if(temp.size()==nums.size())
         {
             ans.insert(temp);
             return;
         }
         for(int i=0; i<nums.size(); i++){
             if(vis[i]==0){
                
                 temp.push_back(nums[i]);
                 vis[i]=1;
                 dfs(nums, temp, ans, vis);
                 vis[i]=0;
                 temp.pop_back();
             }
         }
     }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
         sort(nums.begin(), nums.end());
       vector<int>temp;
         vector<int>vis(nums.size(), 0);
        set<vector<int> >ans;
        dfs(nums, temp, ans, vis);
        vector<vector<int> >st;
        for(auto itr = ans.begin(); itr!=ans.end(); ++itr)
            st.push_back(*itr);
        return st;
    }
};