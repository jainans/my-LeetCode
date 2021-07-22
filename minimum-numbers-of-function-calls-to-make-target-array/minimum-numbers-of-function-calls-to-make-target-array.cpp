class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=  nums.size();
        int maxo=1;
        int cnt=0;
        int curr;
        for(auto & i : nums){
            curr=0;
            while(i){
                if(i%2)
                    cnt++;
                i/=2;
                curr++;
            }
            maxo = max(curr, maxo);
        }
        return maxo-1+cnt;
    }
};