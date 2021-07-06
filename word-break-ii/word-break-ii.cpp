class Solution {
public:
    void solve(unordered_map<string, int>mp, int st, string s, vector<string> temp, vector<vector<string> >& ans ){
        if(st==s.size()){
            ans.push_back(temp);
            temp.pop_back();
            return;
        }
        for(int i=st; i<s.size(); i++){
            string p = s.substr(st, i-st+1);
            if(mp[p]==1){
                temp.push_back(p);
                solve(mp, i+1, s, temp, ans);
                temp.pop_back();
            }
        }
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, int>mp;
        for(auto st : wordDict)
            mp[st]=1;
        vector<string>temp;
        vector<vector<string> >ans;
        solve(mp, 0, s, temp, ans);
        vector<string>res;
        for(int i=0; i<ans.size(); i++){
            string ss = ans[i][0];
            for(int j=1; j<ans[i].size(); j++){
                ss += " "+ans[i][j];
            }
            res.push_back(ss);
            
        }
        return res;
    }
};