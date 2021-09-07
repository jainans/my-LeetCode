class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        //very nice question
        // dp of pair
        // dp[a, b] = dp[b-a, a] + 1;
        
        int n = arr.size();
        unordered_map<int, int>mp;
        unordered_map<int, int>id;
        for(int i=0; i<n; i++){
            id[arr[i]]=i;
        }
        int ans=0;
        for(int i=2; i<n; i++){
            for(int j=0; j<i; j++){
                if(arr[i]-arr[j]<arr[j] && id.find(arr[i]-arr[j])!=id.end()){
                mp[j*n+i] = 1 + mp[n*(id[arr[i]-arr[j]])+j];
                    ans=  max(ans, 2+mp[j*n+i]);
                }
            }
        }
        return ((ans >= 3) ? ans : 0);
    }
};