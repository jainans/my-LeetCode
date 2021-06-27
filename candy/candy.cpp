class Solution {
public:
    int candy(vector<int>& ratings) {
         int n = ratings.size();
        if(n==1)
            return 1;
        vector<int>peaks;
        for(int i=0; i<n; i++){
            if(i==0){
                if(ratings[1]<ratings[0])
                    peaks.push_back(0);
            }
            else if(i==n-1){
                if(ratings[n-1]>ratings[n-2])
                    peaks.push_back(n-1);
            }
            else if( ratings[i]>=ratings[i-1] && ratings[i]>=ratings[i+1])
                peaks.push_back(i);
        }
        int num=0;
        int ans=0;
       
        for(int i=0; i<peaks.size(); i++){
             num++;
            int p = peaks[i]-1;
            int q = peaks[i]+1;
            int pp=0;
            int qq=0;
            while(p>=0 && ratings[p]<ratings[p+1]){
                p--;
                pp++;
                num++;
            }
            while(q<n && ratings[q]<ratings[q-1]){
                q++;
                qq++;
                num++;
            }
            ans+=1+max(pp, qq)+pp*(pp+1)/2+qq*(qq+1)/2;
        }
        ans+=n-num;
        return ans;
    }
};