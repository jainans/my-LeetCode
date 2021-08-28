class Solution {
public:
    int minFlips(int a, int b, int c) {
        int cnt=0;
        int p, q, r;
        for(int i=0; i<32; i++){
            p = a & (1 << i);
            q = b & (1 << i);
            r = c & (1 << i);
            if(r!=0){
                if(p==0 && q==0)
                    cnt++;
            }
            else{
                if(p!=0)
                    cnt++;
                if(q!=0)
                    cnt++;
            }
        }
        return cnt;
    }
};