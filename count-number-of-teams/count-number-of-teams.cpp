class Solution {
public:
    int getSum(int idx, vector<int>& bit){
        int sum=0;
        while(idx>0){
            sum+=bit[idx];
            idx-= (idx & (-idx));
        }
        return sum;
    }
    void update(int idx, vector<int>& bit, int inc){
        while(idx<bit.size()){
            bit[idx]+=inc;
            idx+= (idx & (-idx));
        }
    }
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int maxo = INT_MIN;
        for(auto i : rating)
            maxo = max(maxo, i);
        vector<int>bit(maxo+2, 0);
        int inv;
        int nas=0;
        vector<int>after(n);
        for(int i=n-1; i>=0; i--){
            inv = getSum(rating[i]-1, bit);
            after[i]=  inv;
            update(rating[i], bit, 1);
        }
        for(int i=0; i<=maxo+1; i++)
            bit[i]=0;
        vector<int>before(n);
        for(int i=0; i<n; i++){
            inv = getSum(rating[i]-1, bit);
            before[i]=inv;
            update(rating[i], bit, 1);
        }
        for(int i=0; i<n; i++){
            nas+=(before[i])*(n-1-i-after[i])+(after[i])*(i-before[i]);
        }
        return nas;
    }
};