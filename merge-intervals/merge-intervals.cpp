class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        int l = intervals[0][0];
        int r = intervals[0][1];
        vector<vector<int> >ans;
        for(int i=1; i<n; i++){
            if(intervals[i][0]<=r)
                r = max(intervals[i][1], r);
            else{
                vector<int>temp;
                temp.push_back(l);
                temp.push_back(r);
                ans.push_back(temp);
                l = intervals[i][0];
                r = intervals[i][1];
            }
        }
        vector<int>temp;
                temp.push_back(l);
                temp.push_back(r);
                ans.push_back(temp);
        return ans;
    }
};