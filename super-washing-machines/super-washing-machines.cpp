class Solution {
public:
    int findMinMoves(vector<int>& machines) {
         int sum=0;
        for(auto & i : machines){
            sum+=i;
        }
        int n = machines.size();
        if(sum%n!=0)
            return -1;
        int avg = sum/n;
        int ans=0;
        int lf = 0;
        int req;
       int p;
        for(int i=0; i<n; i++){
            req = avg*i;
            p=0;
            if(lf<req)
                p+=req-lf;
            if((sum-lf-machines[i])<(n-1-i)*avg)
                p+=(n-1-i)*avg-(sum-lf-machines[i]);
            ans = max(ans, p);
            lf+=machines[i];
                

        }
        return ans;
    }
};