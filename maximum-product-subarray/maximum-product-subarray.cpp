class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n= nums.size();
        vector<int>maxo(n);
        vector<int>mino(n);
        maxo[0]=mino[0]=nums[0];
        int ans=maxo[0];
        for(int i=1; i<n; i++){
            maxo[i] = max(nums[i], max(mino[i-1]*nums[i], maxo[i-1]*nums[i]));
            mino[i] = min(nums[i], min(mino[i-1]*nums[i], maxo[i-1]*nums[i]));
            ans = max(ans, maxo[i]);
        }
        return ans;
    }
};