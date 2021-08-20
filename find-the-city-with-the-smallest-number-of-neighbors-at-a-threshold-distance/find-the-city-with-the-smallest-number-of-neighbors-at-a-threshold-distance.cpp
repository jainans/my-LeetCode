class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int> >dis(n, vector<int>(n, INT_MAX));
        for(int i=0; i<n; i++){
            dis[i][i]=0;
        }
        for(int i=0; i<edges.size(); i++){
            dis[edges[i][0]][edges[i][1]] = min(edges[i][2], dis[edges[i][0]][edges[i][1]]);
            dis[edges[i][1]][edges[i][0]] = min(edges[i][2], dis[edges[i][1]][edges[i][0]]);
        }
        for(int mid=0; mid<n; mid++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(dis[i][mid]!=INT_MAX && dis[mid][j]!=INT_MAX)
                        dis[i][j] = min(dis[i][j], dis[i][mid]+dis[mid][j]);
                }
            }
        }
        int mincnt=INT_MAX;
        int id=-1;
        for(int i=0; i<n; i++){
            int cnt=0;
            for(int j=0; j<n; j++){
                if(dis[i][j]<=distanceThreshold)
                    cnt++;
            }
            if(cnt<=mincnt){
                mincnt=cnt;
                id=i;
            }
        }
        return id;
    }
};