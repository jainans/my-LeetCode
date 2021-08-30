 bool comp(string a, string b){
    int x = a.length();
    int y = b.length();
    return (x<y);
}
class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), comp);
        unordered_map<string, int>mp;
        int nas=1;
        for(auto word : words){
            int qp=1;
            for(int j=0; j<word.size(); j++){
                string p = word;
                p.erase(p.begin() + j);
                if(mp.find(p)!=mp.end()){
                    qp = max(qp, 1+mp[p]);
                }
            }
            mp[word] = qp;
            nas = max(nas, qp);
            
        }
        return nas;
    }
};