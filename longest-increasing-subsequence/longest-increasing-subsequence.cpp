class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int>v;
        for(auto i : nums){
            int p = lower_bound(v.begin(), v.end(), i)-v.begin();
            if(p==v.size())
                v.push_back(i);
            else
                v[p]=i;
        }
        return v.size();
    }
};