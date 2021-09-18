class Solution {
public:
    int minOperations(vector<int>& nums) {
        //the basic idea is that the answer array will always start from 
        //one of the given value
        set<int>st;
        for(auto & i : nums){
            st.insert(i);
        }
        int n = nums.size();
        vector<int>v(st.begin(), st.end());
        int ans = nums.size();
        for(int i=0; i<v.size(); i++){
            int k = lower_bound(v.begin(), v.end(), v[i]+n-1)-v.begin();
            if(k==v.size() || v[k]>v[i]+n-1)
                k--;
            ans = min(ans, n-k+i-1);
        }
        return ans;
    }
};