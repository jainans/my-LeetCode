bool comp(vector<int>& a, vector<int>& b){
    if(a[1]<b[1])
        return true;
    if(a[1]==b[1] && a[0]<=b[0])
        return true;
    return false;
}
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end(), comp);
        int n =pairs.size();
        int dp[n];
        dp[0]=1;
        vector<int>v;
        vector<int>maxo(n);
        maxo[0]=dp[0];
        v.push_back(pairs[0][1]);
        for(int i=1; i<n; i++){
            int p = lower_bound(v.begin(), v.end(), pairs[i][0])-v.begin();
            dp[i]=1;
            if(p>0){
                dp[i]+=maxo[p-1];
            }
            maxo[i] = max(maxo[i-1], dp[i]);
            v.push_back(pairs[i][1]);
        }
        return maxo[n-1];
    }
};