class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int i=0;
        while(i<intervals.size() && intervals[i][1]<newInterval[0])
            i++;
        if(i==intervals.size()){
            intervals.push_back(newInterval);
            return intervals;
        }
        int j=intervals.size()-1;
        while(j>=0 && intervals[j][0]>newInterval[1])
            j--;
        vector<vector<int> >ans;
        if(j==-1){
            
            ans.push_back(newInterval);
            for(int p=0; p<intervals.size(); p++){
                ans.push_back(intervals[p]);
            }
            return ans;
        }
        for(int p=0; p<i; p++){
            ans.push_back(intervals[p]);
        }
        vector<int>newto(2);
        newto[0] = min(newInterval[0], intervals[i][0]);
        newto[1] = max(newInterval[1], intervals[j][1]);
        ans.push_back(newto);
        for(int p=j+1; p<intervals.size(); p++){
            ans.push_back(intervals[p]);
        }
        return ans;
        
    }
};