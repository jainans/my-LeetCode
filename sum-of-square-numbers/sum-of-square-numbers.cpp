class Solution {
public:
    bool judgeSquareSum(int c) {
        //FERMAT'S THEOREM 
        // a NUMBER CAN BE expresses as sum of two squares iff any prime factors of form 4k+3
        // repeats an even number of times.
      if(c==0)
          return true;
        while(c%2==0){
            c/=2;
        }
        int p=c;
        for(unsigned int i=3; i*i<=c; i+=2){
            unsigned int cnt=0;
            while(p%i==0){
                p/=i;
                cnt++;
            }
            if(cnt>0 && i%4==3){
                if(cnt%2==1)
                    return false;
            }
            
        }
        if(p>1){
            if(p%4==3)
                return false;
        }
        return true;
        
    }
};