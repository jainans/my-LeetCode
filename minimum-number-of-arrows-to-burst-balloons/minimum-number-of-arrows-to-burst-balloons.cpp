bool comp(vector<int>a, vector<int>b){
    if(a[1]<b[1])
        return true;
    if(a[1]==b[1] && a[0]<b[0])
        return true;
    return false;
}
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), comp);
        int cnt=1;
        int prev = points[0][1];
        for(int i=0; i<points.size(); i++){
            if(points[i][0]<=prev)
                continue;
            cnt++;
            prev =points[i][1];
        }
        return cnt;
    }
};