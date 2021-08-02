class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int ans=0;
        for(int i=0; i<32; i++){
            int p=0;
            for(auto & x : nums){
                if(x & (1<<i))
                    p++;
            }
            ans+=p*(nums.size()-p);
        }
        return ans;
    }
};