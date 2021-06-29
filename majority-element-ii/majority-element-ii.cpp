class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
       int n = nums.size();
        int cnt1=1;
        int cnt2=0;
        int id1=0;
        int id2=-1;
        for(int i=1; i<n; i++){
            if(nums[i]==nums[id1])
                cnt1++;
            else if(cnt2==0){
                cnt2++;
                id2=i;
            }
            else if(nums[i]==nums[id2])
                cnt2++;
            else{
                if(cnt1==0){
                    id1=i;
                    cnt1++;
                }
                else if(cnt2==0){
                    id2==i;
                    cnt2++;
                }
                else{
                cnt1--;
                cnt2--;
                }
            }
        }
        int c1=0;
        int c2=0;
        for(int i=0; i<n; i++){
            if(id1!=-1 && nums[i]==nums[id1])
                c1++;
            if(id2!=-1 && nums[i]==nums[id2])
                c2++;
        }
        vector<int>ans;
        if(c1>n/3)
            ans.push_back(nums[id1]);
        if(c2>n/3)
            ans.push_back(nums[id2]);
        return ans;
    }
};