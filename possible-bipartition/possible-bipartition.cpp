class Solution {
public:
    const static int N = 2005;
    int vis[N];
    vector<int>adj[N];
    bool dfs(int node, int par){
        vis[node] = (par==-1) ? 1 : vis[par]^1;
        for(auto child : adj[node]){
            if(vis[child]==-1){
                if(!dfs(child, node))
                    return false;
                
            }
            else if(vis[child]==vis[node])
                return false;
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        for(int i=0; i<=n; i++){
            vis[i]=-1;
            adj[i].clear();
        }
        for(int i=0; i<dislikes.size(); i++){
            adj[dislikes[i][0]].push_back(dislikes[i][1]);
             adj[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        bool ans = true;
        for(int i=1; i<=n; i++){
            if(vis[i]==-1){
                if(dfs(i, -1)==false)
                    return false;
            }
        }
        return true;
    }
};