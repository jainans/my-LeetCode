class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int totz=0;
        int tot1=0;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='0')
                totz++;
        }
        int z=0;
        int o=0;
        int nas= s.size()+1;
        nas = min(nas, totz);
        int p = s.size()-totz;
        nas = min(nas, p);
        int ro;
        int rz;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='0')
                z++;
            else
                o++;
            rz = totz-z;
           nas=  min(nas, rz+o);
        }
        return nas;
    }
};