bool comp(vector<int>& a, vector<int>& b){
    if(a[0]>b[0])
        return true;
    if(a[0]==b[0] && a[1]<=b[1])
        return true;
    return false;
}

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), comp);
        int n= people.size();
        vector<int>id(n);
        for(int i=0; i<n; i++){
            id[i] = people[i][1];
            for(int j=0; j<i; j++){
                if(id[j]>=id[i])
                    id[j]++;
            }
        }
        vector<vector<int> >ans(n);
        for(int i=0; i<n; i++){
            ans[id[i]] = people[i];
        }
        return ans;
    }
};