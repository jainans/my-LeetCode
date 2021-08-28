class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        //very nice question
        int p=0;
        for(auto i: nums){
            p = p^i;
        }
        if(p!=INT_MIN)
        p &= -p;
        //last set bit of p
        vector<int>ans(2);
        ans[0]=ans[1]=0;
        for(auto i : nums){
            if( i & p)
                ans[0]^=i;
            else
                ans[1]^=i;
        }
        return ans;
    }
};