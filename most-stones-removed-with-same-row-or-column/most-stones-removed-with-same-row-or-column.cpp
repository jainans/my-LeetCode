class Solution {
public:
    static const int N = 20005;
    int vis[N];
    vector<int>adj[N];
    void dfs(int node){
        vis[node]=1;
        for(auto child : adj[node]){
            if(vis[child]==0)
                dfs(child);
        }
        
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();

        unordered_map<int, int>mp;
        for(int i=0; i<n; i++){

            mp[stones[i][0]]=1;
            mp[stones[i][1]+10001] =2;
        }
        for(int i=0; i<n; i++){
            adj[stones[i][0]].push_back(stones[i][1]+10001);
            adj[stones[i][1]+10001].push_back(stones[i][0]);
        }
        int cnt=0;
        for(int i=0; i<=10000; i++){
            if(mp[i]==1 && vis[i]==0)
            {
                dfs(i);
                cnt++;
            }
        }
        for(int i=0; i<=10000; i++){
            if(mp[i+10001]==2 && vis[i+10001]==0){
                dfs(i+10001);
                cnt++;
            }
        }
        return n-cnt;
    }
};