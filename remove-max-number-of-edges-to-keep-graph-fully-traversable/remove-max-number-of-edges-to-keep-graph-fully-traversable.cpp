int find(int x, vector<int>& par){
    if(par[x]==x)
        return x;
    return par[x] = find(par[x], par);
}
void join(int x, int y, vector<int>& par){
    x= find(x, par);
    y=  find(y, par);
    if(x!=y){
        par[x]=y;
    }
}
class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        vector<int>par1(n+1);
        vector<int>par2(n+1);
        for(int i=0; i<=n; i++){
            par1[i]=i;
            par2[i]=i;
        }
        int t=0;
        for(int i=0; i<edges.size(); i++){
            if(edges[i][0]==3){
                if(find(edges[i][1], par1)!=find(edges[i][2], par1)){
                    join(edges[i][1], edges[i][2], par1);
                    join(edges[i][1], edges[i][2], par2);
                    t++;
                    }
            }
        }
        for(int i=0; i<edges.size(); i++){
            if(edges[i][0]==1){
                if(find(edges[i][1], par1)!=find(edges[i][2], par1)){
                    join(edges[i][1], edges[i][2], par1);
                    t++;
                    }
            }
            else if(edges[i][0]==2){
                if(find(edges[i][1], par2)!=find(edges[i][2], par2)){
                    join(edges[i][1], edges[i][2], par2);
                    t++;
                    }
            }
        }
        for(int i=1; i<=n; i++){
            if(find(i, par1)!=find(1, par1) || find(i, par2)!=find(1, par2))
                return -1;
            
        }
        return edges.size()-t;
    }
};