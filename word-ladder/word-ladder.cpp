class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string, int>vis;
        unordered_map<string, int>dis;
        unordered_map<string, int>mp;
        for(int i=0; i<wordList.size(); i++)
            mp[wordList[i]]=1;
        queue<string>q;
        q.push(beginWord);
        vis[beginWord]=1;
        dis[beginWord]=1;
        string t;
        while(!q.empty()){
            string curr = q.front();
            q.pop();
            for(int i=0; i<curr.size(); i++){
               
                for(char c='a'; c<='z'; c++){
                    if(c==curr[i])continue;
                    t = curr;
                    t[i]=c;
                    if(mp.find(t)!=mp.end() && vis.find(t)==vis.end()){
                        q.push(t);
                        vis[t]=1;
                        dis[t] = dis[curr]+1;
                    }
                }
            }
        }
        if(dis.find(endWord)!=dis.end())
            return dis[endWord];
        return 0;
    }
};