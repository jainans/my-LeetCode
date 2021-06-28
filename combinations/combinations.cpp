class Solution {
public:
    void solve(int st, vector<int>temp, vector<vector<int> >& ans, int n, int k){
        if(temp.size()==k){
            ans.push_back(temp);
            temp.pop_back();
            return;
        }
        for(int i=st; i<=n; i++){
            temp.push_back(i);
            solve(i+1, temp, ans, n, k);
            temp.pop_back();
        }
        temp.pop_back();
        return;
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>temp;
        vector<vector<int> >ans;
        solve(1, temp, ans, n, k);
        return ans;
    }
};