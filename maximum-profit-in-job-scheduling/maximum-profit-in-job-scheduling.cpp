class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<pair<int, pair<int, int> > >v(n);
        for(int i=0; i<n; i++){
            v[i].first = endTime[i];
            v[i].second.first = startTime[i];
            v[i].second.second = profit[i];
        }
        sort(v.begin(), v.end());
        
        vector<int>dp(n+1);
        vector<int>mxdp(n+1);
        
        vector<int>bound(n+1, INT_MAX);
        dp[0]=bound[0]=0;
        mxdp[0]=0;
        int ans=0;
        for(int i=1; i<=n; i++){
            int p = upper_bound(bound.begin(), bound.end(), v[i-1].second.first)-bound.begin();
            p--; 
            dp[i] = mxdp[p]+v[i-1].second.second;
            bound[i] = v[i-1].first;
            mxdp[i] = max(mxdp[i-1], dp[i]);
            ans  = max(ans, dp[i]);
        }
        
        return ans;
    }
};