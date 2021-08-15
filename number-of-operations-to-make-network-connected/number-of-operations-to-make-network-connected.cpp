const int N = 1e5+2;
int par[N];
int find(int x){
    if(par[x]==x)
        return x;
    return par[x] =find(par[x]);
}

void join(int x, int y ){
    x = find(x);
    y = find(y);
    if(x!=y){
        par[x]= y;
    }
}

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1)
            return -1;
        for(int i=0; i<n; i++)
            par[i]=i;
        for(int i=0; i<connections.size(); i++){
            if(find(connections[i][0])!=find(connections[i][1]))
                join(connections[i][0], connections[i][1]);
        }
        set<int>ans;
        for(int i=0; i<n; i++){
            ans.insert(find(i));
        }
        return ans.size()-1;
    }
};