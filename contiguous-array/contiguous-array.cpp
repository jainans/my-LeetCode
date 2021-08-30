class Solution {
public:
    int findMaxLength(vector<int>& nums) {
         unordered_map<int, int>mp;
          mp[0] =-1;
        int z=0;
        int on =0;
        int ans=0;
        int curr=0;
          for(auto & i : nums){
              if(i==0)
                  z++;
              else
                  on++;
              if(mp.find((z-on))!=mp.end())
                  ans = max(ans, curr-mp[z-on]);
              else
                  mp[z-on] = curr;
              curr++;
          }
        return ans;
    }
};