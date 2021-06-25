class Solution {
public:
    int find(int node, vector<int>& par){
        if(par[node]==node)
            return node;
        return par[node] = find(par[node], par);
    }
    void join(int a, int b, vector<int>& par){
        a = find(a, par);
        b = find(b, par);
        if(a!=b)
            par[b] = a;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
         int n = edges.size();
        vector<int>par(n+1);
        for(int i=0; i<=n; i++){
            par[i]=i;
        }
        int i;
        for( i=0; i<n; i++){
            int p  = find(edges[i][0], par);
            int q = find(edges[i][1], par);
            if(p!=q)
                join(p, q, par);
            else
                break;
        }
        return edges[i];
    }
};