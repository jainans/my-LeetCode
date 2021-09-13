class Solution {
public:
    void dfs(int node, vector<int>& entry, vector<int>& low, vector<int>& par, vector<vector<int> >& Bridges, vector<vector<int> >& adj){
        static int timer =0;
        entry[node]=timer;
        low[node]=timer;
        timer++;
        for(auto child : adj[node]){
            if(child==par[node])
                continue;
            if(entry[child]==-1)
            {
                par[child]=node;
                dfs(child, entry, low, par, Bridges, adj);
                low[node] = min(low[node], low[child]);
                if(low[child] > entry[node]){
                    vector<int>temp(2);
                    temp[0]=node;
                    temp[1]=child;
                    Bridges.push_back(temp);
                    }
            }
            else{
                //back-edge can't be a bridge
                low[node] = min(low[node], entry[child]);
            }
        }
        
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& con) {
        //do a DFS traversal on the graph
        //keep three arrays low->represents lowest entry time node which can be reached from the node or its subgraph, entry array ->just when a new node is found and parent array ->to store parents
        //while on a node if new child -> ++timer, entry =timer, low = timer;
        // if parent do nothing becuause this edge is dosconnected
        // if other than its a backedge and can't be bridge just update low[node] = min(low[node], entry[child]);
        // while backtracking
        // update low [node] = min(low[node, low[child]]) && check for bridge
        
        vector<vector<int> >adj(n);
        int m = con.size();
        for(int i=0; i<m; i++){
            adj[con[i][0]].push_back(con[i][1]);
            adj[con[i][1]].push_back(con[i][0]);
            
        }
        vector<int>entry(n, -1);
        vector<int>low(n, -1);
        vector<int>par(n, -1);
        
        vector<vector<int> >Bridges;
        for(int i=0; i<n; i++){
            if(entry[i]==-1)
                dfs(i, entry, low, par, Bridges, adj);
        }
        return Bridges;
    }
};