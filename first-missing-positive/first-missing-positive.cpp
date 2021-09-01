class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(nums[i]<=0){
                nums[i] = 400;
            }
        }
        for(int i=0; i<n; i++){
            int p = (nums[i]<0)?-1*nums[i]:nums[i];
            p-=1;
            if(p>=0 && p<n && nums[p]>0)
                nums[p]*=-1;
        }
        int ans = n+1;
        for(int i=0; i<n; i++){
            if(nums[i]>0)
            {
                ans = i+1;
                break;
            }
        }
        for(int i=-10; i<=399; i++){
            cout<<i<<",";
            
        }
        cout<<endl;
        return ans;
        
        
    }
};