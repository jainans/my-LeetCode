class Solution {
public:
    const static int N = 20005;
    int dis[N];
    vector<int>adj[N];
    int vis[N];
    void bfs(int node){
        vis[node]=1;
        dis[node]=0;
        queue<int>q;
        q.push(node);
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            
        for(auto child : adj[curr]){
            if(vis[child]==0){
                vis[child]=1;
                q.push(child);
                dis[child] = 1+dis[curr];
            }
        }
      }
    }
    
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        
        for(int i=0; i<=n; i++){
            vis[i]=0;
            adj[i].clear();
        }
        
        for(int i=0; i<n-1; i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        bfs(0);
     
        int node=0;
        for(int i=0; i<n; i++){
            if(dis[i]>dis[node])
                node =i;
        }
       
        for(int i=0; i<=n; i++){
            vis[i]=0;
           
        }
        bfs(node);
        int maxd=-1;
        int mxnd;
        for(int i=0; i<n; i++){
            if(dis[i]>maxd){
                maxd = dis[i];
                mxnd= i;
            }
        }
        vector<int>ans;
        int preq = maxd/2;
        if(maxd%2!=0)
            preq++;
        int req = maxd/2;
        for(int i=0; i<n; i++){
                ans.push_back(dis[i]);
        }
        for(int i =0; i<n; i++){
            vis[i]=0;
        }
        bfs(mxnd);
    
        vector<int>fil;
        for(int i=0; i<n; i++){
            if(abs(ans[i]-dis[i])<=1 && ans[i]+dis[i]==maxd)
                fil.push_back(i);
        }
        return fil;
    }
};