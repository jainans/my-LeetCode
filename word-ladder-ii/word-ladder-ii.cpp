class Solution {
public:
    vector<vector<string> >ans;
    void dfs(string begin, string end, vector<string>path, unordered_map<string, vector<string> >& adj){
        path.push_back(begin);
        if(begin==end){
            ans.push_back(path);
            path.pop_back();
            return;
        }
        for(auto st : adj[begin]){
            dfs(st, end, path, adj);
            
        }
        path.pop_back();
    }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        //the main idea is to do bfs first to make a special adjacency list which always moves in forward 
        //than we will use this adj and apply dfs to get shortest transformations
        unordered_set<string>st(wordList.begin(), wordList.end());
        unordered_map<string, vector<string> >adj;
        unordered_map<string, int>vis;
        queue<string>Q;
        Q.push(beginWord);
        vis[beginWord]=0;
        while(!Q.empty()){
            string curr = Q.front();
            Q.pop();
            for(int i=0; i<curr.size(); i++){
                for(char c='a'; c<='z'; c++){
                    if(c==curr[i])continue;
                    string q = curr;
                    q[i]=c;
                    if(st.find(q)!=st.end()){
                        if(vis.find(q)==vis.end()){
                            vis[q]=vis[curr]+1;
                            adj[curr].push_back(q);
                            Q.push(q);
                        }
                        else if(vis[q]==vis[curr]+1){
                            adj[curr].push_back(q);
                        }
                    }
                }
            }
        }
        vector<string>path;
        dfs(beginWord, endWord, path, adj);
        return ans;
    }
};