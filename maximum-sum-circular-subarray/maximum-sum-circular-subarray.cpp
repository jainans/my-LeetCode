class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
      int mx1 = INT_MIN;
      int mn1 = INT_MAX;
      int c1=0;
      int c2=0;
        int tot=0;
      for(auto i : nums){
          c1 = max(c1+i, i);
          mx1 = max(mx1, c1);
          c2 = min(c2+i, i);
          mn1 = min(mn1, c2);
          tot+=i;
      }
        return (mn1==tot) ? mx1 : max(mx1, tot-mn1);
    }
};