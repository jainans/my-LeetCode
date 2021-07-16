class Solution {
public:
    int triangleNumber(vector<int>& nums) {
         sort(nums.begin(), nums.end());
        int n= nums.size();
        if(n<3)
            return 0;
        int p, q;
        int r, s;
        int ans=0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                p = nums[j]+nums[i];
                q = nums[j]-nums[i];
                r = upper_bound(nums.begin(), nums.end(), q)-nums.begin();
                s = lower_bound(nums.begin(), nums.end(), p)-nums.begin()-1;
                if(s<0 || r>=nums.size() || r>s)
                    continue;
                ans+=s-r+1;
                if(i>=r && i<=s)
                    ans--;
                if(j>=r && j<=s)
                    ans--;
            }
        }
        return ans/3;
    }
};