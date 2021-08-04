class Solution {
public:
    static const int N = 202;
    vector<int>adj[N];
    int vis[N];
    void dfs(int node){
        vis[node]=1;
        for(auto child : adj[node]){
            if(vis[child]==0){
                dfs(child);
                for(auto ch : adj[child]){
                    if(vis[ch]==0)
                        dfs(ch);
                }
            }
            
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
       int n = isConnected.size();
        for(int i=0;i<n; i++){
            for(int j=0; j<n; j++){
                if(j!=i && isConnected[i][j]==1)
                    adj[i+1].push_back(j+1);
                    
            }
        }
        int cnt=0;
        for(int i=1; i<=n; i++){
            if(vis[i]==0)
            {
                dfs(i);
                cnt++;
            }
        }
        return cnt;
        
    }
};