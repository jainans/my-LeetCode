class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.size()>t.size())
            return false;
        int l=0;
        int r=0;
        while(l<s.size() && r<t.size()){
            if(s[l]==t[r]){
                l++;
            }
            r++;
        }
        if(l==s.size())
            return true;
        return false;
    }
};