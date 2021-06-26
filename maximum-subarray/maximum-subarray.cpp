class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int glo=INT_MIN;
        int mtl = 0;
        for(auto i : nums){
            if(i+mtl<i)
                mtl = i;
            else
                mtl+=i;
            glo=max(glo, mtl);
        }
        return glo;
    }
};