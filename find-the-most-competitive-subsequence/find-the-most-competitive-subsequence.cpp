class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > >pq;
        int n  = nums.size();
        vector<int>ans;
        for(int i=0; i<=n-k; i++){
            pq.push({nums[i], i});
        }
        int prev = pq.top().second;
        ans.push_back(pq.top().first);
        pq.pop();
        for(int i=n-k+1; i<n; i++){
            pq.push({nums[i], i});
            while(!pq.empty() && pq.top().second<prev)
                pq.pop();
            prev = pq.top().second;
            ans.push_back(pq.top().first);
            pq.pop();
        }
        return ans;
        
    }
};