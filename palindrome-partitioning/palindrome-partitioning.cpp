class Solution {
public:
    bool isPal(string s, int l, int r){
         int p =l;
        int q=r;
        while(p<q){
            if(s[p]==s[q]){
                p++;
                q--;
            }
            else
                return false;
        }
        return true;
    }
    void dfs(int st, int n, string s, vector<string>temp, vector<vector<string> >&ans){
        if(st==n)
        {
            ans.push_back(temp);
            temp.pop_back();
            return;
        }
        
        for(int i=st; i<n; i++){
            if(isPal(s, st, i)){
                temp.push_back(s.substr(st, i-st+1));
                dfs(i+1, n, s, temp, ans);
                temp.pop_back();
            }
        }
        
    }
    vector<vector<string>> partition(string s) {
        vector<string>temp;
        vector<vector<string> >ans;
        dfs(0, s.size(), s, temp, ans);
        return ans;
    }
};