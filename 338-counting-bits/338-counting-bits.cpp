class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>init(n+1,0);
      
        int cut=1;
        for(int i=1; i<=n; i++){
            if(i==cut){
                init[i] = 1+init[i-cut];
               
                cut*=2;
            }
            else{
                init[i]=1+init[i-cut/2];
                
            }
        }
        return init;
    }
};