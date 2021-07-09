class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
      vector<int>freq(26, 0);
        for(auto c : p){
            int q = c-'a';
            freq[q]++;
        }
        vector<int>v(26, 0);
        vector<int>ans;
        if(p.size()>s.size())
            return ans;
        for(int i=0; i<p.size(); i++){
            int qq = s[i]-'a';
            v[qq]++;
        }
        if(v==freq)
            ans.push_back(0);
        for(int i=p.size(); i<s.size(); i++){
            int x= s[i-p.size()]-'a';
            int y = s[i]-'a';
            v[x]--;
            v[y]++;
            if(v==freq)
                ans.push_back(i-p.size()+1);
        }
        return ans;
    }
};