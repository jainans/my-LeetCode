class Solution {
public:
    void dfs(int node, int n, vector<int>path, vector<vector<int> >& graph, vector<bool>& vis, vector<vector<int> >& ans){
        if(node==n-1){
            path.push_back(node);
            ans.push_back(path);
            path.pop_back();
            return;
        }
        path.push_back(node);
        vis[node] = true;
        for(auto child : graph[node]){
            if(vis[child]==false)
                dfs(child, n, path, graph, vis, ans);
        }
        vis[node] = false;
        path.pop_back();
        return;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int>path;
        int n = graph.size();
        vector<bool>vis(n, false);
        vector<vector<int> >ans;
        dfs(0, n, path, graph, vis, ans);
        
        return ans;
    }
};