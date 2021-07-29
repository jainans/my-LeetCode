class Solution {
public:
    int count=0;
    void dfs(int pos, vector<int>& vis, int n){
        if(pos>n)
            count++;
        for(int i=1; i<=n; i++){
            if(!vis[i] && (i%pos==0 || pos%i==0)){
                vis[i]=1;
                dfs(pos+1, vis, n);
                vis[i]=0;
            }
        }
    }
    int countArrangement(int n) {
        vector<int>vis(n+1, 0);
        dfs(1, vis, n);
        return count;
    }
};