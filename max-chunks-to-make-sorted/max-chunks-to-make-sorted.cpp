class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n =arr.size();
        vector<int>vis(n, 0);
        int ans=0;
       for(int i=0; i<n; i++){
           vis[arr[i]]=1;
           bool bb = true;
           for(int j=0; j<=i; j++){
               if(vis[j]==0)
               {
                   bb=false;
                   break;
               }
           }
           if(bb)
               ans++;
       }
        return ans;
    }
};