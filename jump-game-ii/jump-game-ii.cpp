class Solution {
public:
    int jump(vector<int>& nums) {
        int mtill = 0;
        int n=  nums.size();
        int i=0;
        int ans=0;
        if(n==1)
            return 0;
        while(1){
            int mxid = i-1;
            for(int p = i; p<=mtill; p++){
                mxid = max(mxid, p+nums[p]);
            }
            ans++;
            i=mtill+1;
            mtill = mxid;
            if(mtill>=n-1)
                return ans;
        }
    }
};