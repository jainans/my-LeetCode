class Solution {
public:
    void solve(int n, vector<int>& v, vector<int>temp, vector<vector<int> >& ans){
        if(temp.size()==n){
            ans.push_back(temp);
            temp.pop_back();
            return;
        }
        for(int i=0; i<v.size(); i++){
            temp.push_back(v[i]);
            vector<int>tt;
            for(int j=0; j<v.size(); j++){
                if(j==i)
                    continue;
                tt.push_back(v[j]);
            }
            solve(n, tt, temp, ans);
            temp.pop_back();
        }
       
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>temp;
        vector<vector<int> >ans;
        int n = nums.size();
        solve(n, nums, temp, ans);
        return ans;
    }
};