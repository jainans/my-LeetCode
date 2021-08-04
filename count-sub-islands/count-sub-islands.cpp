class Solution {
public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    static const int N = 501;
    void dfs(int x, int y, vector<vector<int>>& grid, int& p){
        grid[x][y]=p;
        for(int i=0; i<4; i++){
            int cx = x+dx[i];
            int cy = y+dy[i];
            if(cx>=0 && cx<grid.size() && cy>=0 && cy<grid[0].size()){
                if(grid[cx][cy]==1)
                    dfs(cx, cy, grid, p);
            }
        }
    }
    void dfs2(bool& bb, int x, int y, vector<vector<int> >& grid, int& p, vector<vector<int> >& gd){
        grid[x][y]=2;
        if(gd[x][y]!=p)
            bb=false;
        for(int i=0; i<4; i++){
            int cx = x+dx[i];
            int cy = y+dy[i];
             if(cx>=0 && cx<grid.size() && cy>=0 && cy<grid[0].size()){
                if(grid[cx][cy]==1)
                    dfs2(bb, cx, cy, grid, p, gd);
            }
        }
    }
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int p=2;
        int n = grid1.size();
        int m =  grid1[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid1[i][j]==1){
                    dfs(i, j, grid1, p);
                    p++;
                }
            }
        }
        int cnt=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid2[i][j]==1){
                    bool bb = true;
                    int p= grid1[i][j];
                    dfs2(bb, i, j, grid2, p, grid1);
                    if(bb && p!=0)
                        cnt++;
                }
            }
        }
        return cnt;
    }
};