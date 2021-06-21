class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==INT_MIN && divisor==-1)
            return INT_MAX;
        if(divisor==0)
            return INT_MAX;
        int p = 1;
        if((dividend<0 && divisor>0) || (dividend>0 && divisor<0))
            p=-1;
        long long int a = abs(dividend);
        long long int b = abs(divisor);
        if(a<b)
            return 0;
        long long int nas=0;
        int l;
        while(1){
        l=0;
        if(a<b)
            break;
        while((b<<l)<=a){
            l++;
        }
        nas+=1<<(l-1);
        a-=b<<(l-1);
        }
        if(p==-1)
            nas = nas-nas-nas;
        return nas;
    }
};