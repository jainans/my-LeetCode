class Solution {
public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    const static int N = 302;
    int vis[N][N];
    void dfs(int x, int y, vector<vector<char>>& grid){
        vis[x][y]=1;
        for(int i=0; i<4; i++){
            int cx =  x+dx[i];
            int cy = y+dy[i];
            if(cx>=0 && cx<grid.size() && cy>=0 && cy<grid[0].size()){
                if(vis[cx][cy]==0 && grid[cx][cy]=='1')
                    dfs(cx, cy, grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=  grid.size();
        int m = grid[0].size();
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++)
                vis[i][j]=0;
        }
        int cnt=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]=='1' && vis[i][j]==0)
                {
                    dfs(i, j, grid);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};