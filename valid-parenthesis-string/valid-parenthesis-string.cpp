class Solution {
public:
    bool checkValidString(string s) {
        int mino=0;
        int maxo =0;
        for(auto c :s){
            if(c=='('){
                mino++;
                maxo++;
            }
            else if(c==')'){
                if(maxo==0)
                    return false;
                mino = max(0, mino-1);
                maxo--;
                
            }
            else{
                mino = max(0, mino-1);
                maxo++;
            }
            if(maxo<0)
                return false;
        }
        if(mino<=0 && maxo>=0)
            return true;
        return false;
    }
};