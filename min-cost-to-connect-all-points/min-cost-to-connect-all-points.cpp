class Solution {
public:
    static const int N = 1001;
    int par[N];
    int find(int node){
        if(par[node]==node)
            return node;
        return par[node] = find(par[node]);
    }
    void onion(int a, int b){
        a = find(a);
        b = find(b);
        if(a!=b)
            par[b]=a;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n= points.size();
        vector<pair<int, pair<int, int> > >v;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int x = abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                v.push_back({x, {i, j} });
            }
        }
        sort(v.begin(), v.end());
        for(int i=0; i<n; i++)
            par[i]=i;
        int ans=0;
        for(int i=0; i<v.size(); i++){
            if(find(v[i].second.first)!=find(v[i].second.second))
            {
                 onion(v[i].second.first, v[i].second.second);
                 ans+=v[i].first;
            }
        }
        return ans;
    }
};