
class Solution {
public:
    long long numberOfWeeks(vector<int>& ms) {
      long long sum = 0;
      long long maxo = INT_MIN;
        for(long long i : ms){
            sum+=i;
            maxo = max(maxo, i);
        }
        if((sum-maxo)+1>=maxo)
            return sum;
        return 2*(sum-maxo)+1;
    }
};