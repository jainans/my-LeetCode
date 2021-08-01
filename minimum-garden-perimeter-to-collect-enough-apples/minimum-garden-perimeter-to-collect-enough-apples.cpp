#define ll long long int
class Solution {
public:
    long long minimumPerimeter(long long neededApples) {
        ll leval=0;
        ll p =4;
        ll num=3;
        ll x=5;
        while(neededApples>0){
            neededApples-=4*x-2*p;
            x +=num+p+4;
            p+=4;
            num+=2;
            leval++;
        }
        ll ans  = 8*leval;
        return ans;
    }
};