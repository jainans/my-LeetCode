class Solution {
public:
    void solve(int st, int sum, vector<int>& v, int n, vector<int>temp, vector<vector<int> >& ans){
        if(st>=n)
            return;
        if(sum==0){
            ans.push_back(temp);
            temp.pop_back();
            return;
        }
        if(sum<0){
            temp.pop_back();
            return;
        }
        solve(st+1, sum, v, n, temp, ans);
        temp.push_back(v[st]);
        solve(st, sum-v[st], v, n, temp, ans);
        temp.pop_back();
       
        return ;
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int>temp;
        vector<vector<int> >ans;
        solve(0, target, candidates, candidates.size(), temp, ans);
        return ans;
    }
};