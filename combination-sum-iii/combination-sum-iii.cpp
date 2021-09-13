class Solution {
public:
    void dfs(int st, int n, int k, vector<int> temp, vector<vector<int> >& ans){
        if(n==0 && k==0){
            ans.push_back(temp);
            temp.pop_back();
            return;
        }
        if(k==0 || n==0){
            temp.pop_back();
            return;
        }
        for(int i=st; i<=9; i++){
            temp.push_back(i);
            dfs(i+1, n-i, k-1, temp, ans);
            temp.pop_back();
           
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        int st=1;
        vector<int>temp;
        vector<vector<int> >ans;
        dfs(st, n, k, temp, ans);
        return ans;
    }
};