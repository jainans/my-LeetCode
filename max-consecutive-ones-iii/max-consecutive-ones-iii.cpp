class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        vector<int>zeros;
        int n = nums.size();
        zeros.push_back(-1);
        for(int i=0; i<n; i++){
            if(nums[i]==0)
                zeros.push_back(i);
            
        }
        zeros.push_back(n);
        if(zeros.size()-2<=k)
            return n;
        int l=1;
        int r = l+k-1;
        int nas=0;
        while(r<=zeros.size()-1){
            nas = max(nas, zeros[r+1]-zeros[l-1]-1);
            l++;
            r++;
        }
        return nas;
    }
};