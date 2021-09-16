class Solution {
public:
    int cost[1001];
    int time[1001];
    vector<vector<int> >adj[1001];
    
    int dijkstra(int src, int dest, int maxTime){
        for(int i=1; i<=dest; i++){
            cost[i]=INT_MAX;
            time[i]=INT_MAX;
            
        }
        
        priority_queue<vector<int>, vector<vector<int> >, greater<vector<int> > >pq;
        pq.push({cost[src], time[src], src});
        
        while(!pq.empty()){
            vector<int>v= pq.top();
            pq.pop();
            int c = v[0];
            int t = v[1];
            int node = v[2];
            
            for(vector<int> child : adj[node]){
                if(t+child[2]<=maxTime){
                    if(c+child[1]<cost[child[0]]){
                        cost[child[0]] = c+child[1];
                        pq.push({cost[child[0]], t+child[2], child[0]});
                    }
                    else if(t+child[2]<time[child[0]]){
                        time[child[0]]=t+child[2];
                        pq.push({c+child[1], time[child[0]], child[0]});
                    }
                }
            }
        }
        return cost[dest];
        
    }
    
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        // variation of dijkstra algorithm
        // in classic dijkstra we use only time to minimize but here we will store both cost and time in the priority _queue to imize,
        // first cost than time
        //only traverse those edges which does not increase time from maxTime
        // when you find a new edge which is reducing the cost include it 
        //else if the time is getting reduced than also include it
        cost[0] = passingFees[0];
        time[0]=0;
        for(int i=0; i<=passingFees.size(); i++){
            adj[i].clear();
        }
        for(int i=0; i<edges.size(); i++){
            adj[edges[i][0]].push_back({edges[i][1], passingFees[edges[i][1]], edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0], passingFees[edges[i][0]], edges[i][2]});
        }
        int ans =  dijkstra(0, passingFees.size()-1, maxTime);
        if(ans==INT_MAX)
            return -1;
        return ans;
        
    }
};