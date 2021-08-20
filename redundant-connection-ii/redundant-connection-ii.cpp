class Solution {
public:
    int find(vector<int>& dis, int i){
        if(dis[i]==0) 
            return i;
        return dis[i]=find(dis, dis[i]);
    }
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        int par[n+1];
        vector<int>dis(n+1, 0);
        for(int i=0; i<=n; i++)
            par[i]=-1;
        int last=-1;
        int first=-1;
        int second =-1;
        for(int i=0; i<n; i++){
            int p = edges[i][0];
            int c = edges[i][1];
            if(par[c]!=-1){
                first = par[c];
                second =i;
                continue;
            }
            par[c]=i;
            int dp = find(dis, p);
            if(dp==c){
                last = i;
            }
            else
                dis[c]=dp;
        }
        if(last==-1)
            return edges[second];
        if(second==-1)
            return edges[last];
        return edges[first];
    }
};