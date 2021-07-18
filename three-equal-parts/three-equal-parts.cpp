class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        int n  =arr.size();
        int cnt=0;
        for(int i=0; i<n; i++){
            if(arr[i]==1)
                cnt++;
        }
        if(cnt%3!=0)
            return {-1, -1};
        vector<int>ans;
        if(cnt==0 )
            return {0, 2};
        int fst;
        int fed;
        int sst;
        int sed;
        int tst;
        int ted;
        int cp=0;
        for(int i=0; i<n; i++){
            if(arr[i]==1){
                cp++;
                if(cp==1)
                    fst=i;
                if(cp==1+cnt/3)
                    sst=i;
                if(cp==1+2*cnt/3)
                    tst=i;
            }
        }
        ted=n-1;
        fed  = fst+ted-tst;
        sed = sst+ted-tst;
        if(sst>fed && tst>sed){
            bool bb = true;
            int l=fst;
            int r = sst;
            while(l<=fed && r<=sed){
                if(arr[l]!=arr[r])
                {
                    bb=false;
                    break;
                }
                l++;
                r++;
            }
            if(!bb)
                return {-1, -1};
            l=sst;
            r = tst;
            while(l<=sed && r<=ted){
                if(arr[l]!=arr[r]){
                    bb= false;
                    break;
                }
                l++;
                r++;
            }
            if(!bb)
                return {-1, -1};
            return {fed, sed+1};
        }
        else
            return {-1, -1};
        

    }
};