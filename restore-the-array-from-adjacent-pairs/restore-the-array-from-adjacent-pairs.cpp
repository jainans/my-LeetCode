class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adj) {
        unordered_map<int, vector<int> >mp;
        for(int i=0; i<adj.size(); i++){
            mp[adj[i][0]].push_back(adj[i][1]);
            mp[adj[i][1]].push_back(adj[i][0]);
        }
        int st;
        for(int i=0; i<adj.size(); i++){
            if(mp[adj[i][0]].size()==1)
            {
                st=adj[i][0];
                break;
            }
            if(mp[adj[i][1]].size()==1)
            {
                st=adj[i][1];
                break;
            }
        }
        vector<int>ans;
        ans.push_back(st);
        ans.push_back(mp[st][0]);
        int prev = st;
        int curr = mp[st][0];
        
       while(ans.size()<=adj.size()){
           if(mp[curr][0]!=prev){
               ans.push_back(mp[curr][0]);
               prev = curr;
               curr = mp[curr][0];
           }
           else{
               if(mp[curr].size()>1){
                  ans.push_back(mp[curr][1]);
               prev = curr;
               curr = mp[curr][1];
               }
           }
       }
        return ans;
    }
};