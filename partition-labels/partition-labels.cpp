class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>v;
        int n = s.size();
        int t=0;
        vector<int>last(26);
        for(int i=0; i<n; i++){
            int p = s[i]-'a';
            last[p]=i;
        }
        while(t<n){
            int q = last[s[t]-'a'];
            
            for(int i=t; i<=q; i++){
                q= max(q, last[s[i]-'a']);
            }
            v.push_back(q-t+1);
            t=q+1;
        }
        return v;
    }
};