class Solution {
public:
    string removeDuplicates(string s) {
        int n = s.size();
        if(n<=1)
            return s;
       string ans = "";
        ans+=s[0];
        for(int i=1; i<n; i++){
            if(ans!="" && ans[ans.size()-1]==s[i])
                ans.pop_back();
            else
                ans.push_back(s[i]);
        }
        return ans;
    }
};