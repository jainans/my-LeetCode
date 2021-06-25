class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int>mp;
        vector<int>ans(2);
        for(int i=0; i<nums.size(); i++){
            if(mp[target-nums[i]]>0)
            {
                ans[0] = mp[target-nums[i]]-1;
                ans[1]=i;
                break;
            }
            else
                mp[nums[i]]=i+1;
        }
        return ans;
    }
};