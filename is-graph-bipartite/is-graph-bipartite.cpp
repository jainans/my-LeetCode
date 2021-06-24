class Solution {
public:
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& vis, int par){
        vis[node] = (par==-1) ? 1 : (vis[par]^1);
        for(auto child : graph[node]){
            if(vis[child]==-1)
            {
               if(dfs(child, graph, vis, node)==false)
                   return false;
                
            }
            else if(vis[child]==vis[node])
                return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n= graph.size();
        vector<int>vis(n, -1);
        bool bb=  true;
        for(int i=0; i<n; i++){
            if(vis[i]==-1){
              bool bc = dfs(i, graph, vis, -1);
                if(bc==false)
                    return false;
            }
        }
        return true;
    }
};