class Solution {
public:
    void dfs(int st, string dg, int n, string temp, vector<string>& given, vector<string>& ans){
        if(st==n){
            ans.push_back(temp);
            return;
        }
        int p = dg[st]-'0';
        for(int i=0; i<given[p].size(); i++){
            temp.push_back(given[p][i]);
            dfs(st+1, dg, n, temp, given, ans);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>given=  {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string>ans;
        string temp = "";
        int n = digits.size();
        if(n==0)
            return ans;
        dfs(0, digits, n, temp, given, ans);
        return ans;
    }
};