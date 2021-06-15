class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        int sum=0;
        int maxo = INT_MIN;
        for(int i=0; i<n; i++){
            sum+=nums[i];
            maxo = max(maxo, nums[i]);
        }
        int l=maxo;
        int r= sum;
         int ans;
        while(l<=r){
            int mid = l+(r-l)/2;
            int cnt=0;
            int p=0;
            for(int i=0; i<n; i++){
                p+=nums[i];
                if(p>mid){
                    cnt++;
                    p = nums[i];
                }
            }
            cnt++;
           
            if(cnt>m)
                l = mid+1;
           
            else{
                ans= mid;
                r = mid-1;
            }
        }
        return ans;
    }
};