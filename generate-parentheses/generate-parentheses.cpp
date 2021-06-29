class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        if(n==1){
            string s = "()";
            ans.push_back(s);
            return ans;
        }
        unordered_map<string, int>mp;
        for(int i=1; i<n; i++){
            vector<string>v1 = generateParenthesis(i);
            vector<string>v2 = generateParenthesis(n-i);
            for(int j=0; j<v1.size(); j++){
                for(int k=0; k<v2.size(); k++){
                    string p = v1[j];
                    p.append(v2[k]);
                    if(mp[p]==0){
                        ans.push_back(p);
                        mp[p]=1;
                    }
                        
                }
            }
        }
        vector<string>v3 = generateParenthesis(n-1);
        for(int i=0; i<v3.size(); i++){
            string p  = "(";
            p.append(v3[i]);
            p.append(")");
            ans.push_back(p);
        }
        return ans;
        
    }
};