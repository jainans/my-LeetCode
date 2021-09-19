class Solution {
public:
    void comb(int id, string s, int n, set<string>& ans){
        if(id==n){
            ans.insert(s);
            return ;
        }
        for(int i=id; i<n; i++){
        swap(s[id], s[i]);
        comb(id+1, s, n, ans);
        swap(s[id], s[i]);
        }
    }
    bool contains(string & s, string & chk, int m, int k){
        int l=0;
        int r=0;
        int cnt=0;
        while(l<s.size()){
            if(s[l]==chk[r]){
                r = (r+1)%m;
                if(r==0)
                    cnt++;
                
            }
            if(cnt==k)
                return true;
            l++;
        }
        return false;
    }
    
    string longestSubsequenceRepeatedK(string s, int k) {
        string p = "";
        vector<int>freq(26, 0);
        for(auto & i : s){
            int y = i-'a';
            freq[y]++;
        }
        for(int i=0; i<26; i++){
            for(int j=0; j<freq[i]/k; j++){
                p+=('a'+i);
            }
        }
        int m = p.size();
        vector<string>pp;
        for(int i=0; i < (1 << m); i++){
            string q = "";
            for(int j=0; j<m; j++){
                if((1 << j) & i)
                    q+=p[j];
            }
            pp.push_back(q);
        }
        set<string>ct;
        for(int i=0; i<pp.size(); i++){
            comb(0, pp[i], pp[i].size(), ct);
        }
        vector<string>tt(ct.begin(), ct.end());
        sort(tt.begin(), tt.end());
        
        string ans="";
        for(int i=1; i<tt.size(); i++){
            if(tt[i]=="")
                continue;
            bool bb = contains(s, tt[i], tt[i].size(), k);
            if(bb && tt[i].size()>=ans.size())
                ans =tt[i];
        }
        return ans;
    }
};