class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //topo-sort problem 
        //start from outdegree 0 nodes
        //keep removing them and adding in a vector
        //use bfs like system
        // at last check if your array contains all n elements
        int n= numCourses;
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
            for(auto j : adj[bfs[i]]){
                if(--degree[j]==0)
                    bfs.push_back(j);
            }
        }
        return (bfs.size()==n);
    }
};