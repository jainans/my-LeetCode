class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        int cnt;
        for(int i=0; i<32; i++){
            cnt=0;
            for(int j=0; j<nums.size(); j++){
                if(nums[j] & (1<<i))
                    cnt++;
            }
            if(cnt%3==1)
                ans |= (1<<i);
        }
        return ans;
    }
};