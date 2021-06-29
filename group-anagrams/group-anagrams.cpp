class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       map<vector<int>, vector<string> >mp;
        for(int i=0; i<strs.size(); i++){
            vector<int>v(26, 0);
            for(int j=0; j<strs[i].size(); j++){
                int p = strs[i][j]-'a';
                v[p]++;
            }
            mp[v].push_back(strs[i]);
        }
        vector<vector<string> >ans;
        for(auto it : mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};