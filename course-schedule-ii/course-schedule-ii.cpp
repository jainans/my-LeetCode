class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int> >adj(n);
        vector<int>degree(n, 0);
        for(int i=0; i<prerequisites.size(); i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            degree[prerequisites[i][0]]++;
        }
        vector<int>bfs;
        for(int i=0; i<n; i++){
            if(degree[i]==0)
                bfs.push_back(i);
        }
        for(int i=0; i<bfs.size(); i++){
            for(auto j : adj[bfs[i]])
                if(--degree[j]==0)bfs.push_back(j);
        }
        vector<int>empty;
        if(bfs.size()==n)
            return bfs;
        else
            return empty;
    }
};