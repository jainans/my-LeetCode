class Solution {
public:
    const static int N = 305;
    int dp[N];
    int solve(string s, unordered_map<string, int> &mp, int id){
        if(id==s.size())
            return 1;
        if(dp[id]!=-1)
            return dp[id];
        int f=0;
        for(int i=id; i<s.size(); i++){
            string t = s.substr(id, i-id+1);
            if(mp[t]==1){
                int q = solve(s, mp, i+1);
                if(q==1)
                    f=1;
            }
        }
        return dp[id]= f;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        for(int i=0; i<n; i++){
            dp[i]=-1;
        }
        unordered_map<string, int>mp;
        for(int i=0; i<wordDict.size(); i++){
            mp[wordDict[i]] = 1;
        }
        int ans =  solve(s, mp, 0);
        if(ans==1)
            return true;
        return false;
    }
};