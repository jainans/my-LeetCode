class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int n = nums.size();
        int pz = -1;
        int fpneg = -1;
        int numneg=0;
        int ans=0;
        for(int i=0; i<n; i++){
            if(nums[i]==0){
                pz=i;
                fpneg=-1;
                numneg=0;
            }
            if(nums[i]<0 ){
                if(fpneg<0)
                    fpneg=i;
                numneg++;
            }
            if(numneg%2==0){
                ans = max(ans, i-pz);
            }
            else{
                ans = max(ans, i-fpneg);
            }
        }
        return ans;
        
    }
};