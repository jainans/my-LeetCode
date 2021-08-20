class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int dis[n+1];
        for(int i=0; i<=n; i++)
            dis[i]=INT_MAX;
        dis[k]=0;
        vector<vector<pair<int, int> > >adj(n+1);
        for(int i=0; i<times.size(); i++){
            adj[times[i][0]].push_back({times[i][1], times[i][2]});
             
        }
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > >pq;
        pq.push({0, k});
        while(!pq.empty()){
            int cn = pq.top().second;
            int cd = pq.top().first;
            pq.pop();
            if(dis[cn]!=cd)
                continue;
            for(auto p : adj[cn]){
                if(dis[p.first]>p.second+cd){
                    dis[p.first]=p.second+cd;
                    pq.push({p.second+cd, p.first});
                }
            }
        }
        int ans = -1;
        for(int i=1; i<=n; i++){
            if(dis[i]==INT_MAX)
                return -1;
            ans = max(ans, dis[i]);
        }
        return ans;
    }
};