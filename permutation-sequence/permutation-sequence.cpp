class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int>fact(n+1);
        fact[0]=1;
        for(int i=1; i<=n; i++){
            fact[i]=fact[i-1]*(i);
        }
        string nas="";
        string q = "";
        for(int i=1; i<=n; i++){
            char c = i+'0';
            q+=c;
        }
        for(int i=n-1; i>=1; i--){
            int pp = ceil(k*1.0/fact[i]);
            nas+=q[pp-1];
            string t ="";
            for(int j=0; j<q.size(); j++){
                if(j!=pp-1)
                    t+=q[j];
                
            }
            q = t;
           k-=(pp-1)*fact[i];
            
        }
        nas+=q[0];
        return nas;
    }
};