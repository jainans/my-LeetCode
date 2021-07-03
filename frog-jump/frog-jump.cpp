class Solution {
public:
    map<pair<int,int>, bool>mp;
    bool solve(vector<int>& num, int id=0, int k=0){
        if(mp.find({id, k})!=mp.end())
            return mp[{id, k}];
        for(int i=id+1; i<num.size(); i++){
            int gap = num[i]-num[id];
            if(gap>k+1)
                return mp[{id, k}]= false;
            if(gap<k-1)
                continue;
            if(solve(num, i, gap))return mp[{id, k}]= true;
        }
        return mp[{id, k}]= (id==num.size()-1);
    }
    bool canCross(vector<int>& stones) {
       return solve(stones);
    }
};