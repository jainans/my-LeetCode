class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n==0)
            return 0;
        unordered_map<char, int>mp;
        int l=0;
        mp[s[0]]=0;
        int nas=1;
        for(int i=1; i<n; i++){
            if(mp.find(s[i])!=mp.end() && mp[s[i]]>=l){
                nas = max(nas, i-l);
                l = mp[s[i]]+1;
                
            }
            mp[s[i]]=i;
        }
        nas = max(nas, n-l);
        return nas;
    }
};