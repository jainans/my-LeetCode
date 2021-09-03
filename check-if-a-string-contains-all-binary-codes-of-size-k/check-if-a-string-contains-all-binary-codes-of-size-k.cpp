class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.size();
        if(n < (1 << k) + k-1)
            return false;
        int p=0;
        for(int i=k-1; i>=0; i--){
            if(s[i]=='1')
                p |= (1 << (k-1-i));
        }
        set<int>st;
        st.insert(p);
        int r = k;
        int l = r-k;
        
        while(r<n){
            if(s[l]=='1')
                p-=(1 <<(k-1));
            p*=2;
            if(s[r]=='1')
                p+=1;
            st.insert(p);
            l++;
            r++;
        }
        if(st.size()== ( 1<< k))
            return true;
        return false;
    }
};