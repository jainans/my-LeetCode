class Solution {
public:
    string orderlyQueue(string s, int k) {
        //very good intution
        // you can swap any two adjacent elements withot changing others by 2             //  element swap
        int n = s.size();
        if(k==1){
            string ans=s;
            for(int i=0; i<n; i++){
                string p = s.substr(i)+s.substr(0, i);
                if(p<ans)
                    ans=p;
            }
            return ans;
        }
        else{
            sort(s.begin(), s.end());
            return s;
        }
    }
};