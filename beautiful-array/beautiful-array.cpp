class Solution {
public:
    void solve(vector<int>& num){
        if(num.size()<=2)
            return;
        if(num.size()==3){
            swap(num[0], num[1]);
            return;
        }
        vector<int>tmp1;
        vector<int>tmp2;
        for(int i=0; i<num.size(); i+=2){
            tmp1.push_back(num[i]);
        }
        for(int i=1; i<num.size(); i+=2)
            tmp2.push_back(num[i]);
        solve(tmp1);
        solve(tmp2);
        for(int i=0; i<tmp1.size(); i++){
            num[i]=tmp1[i];
        }
        for(int i=0; i<tmp2.size(); i++){
            num[i+tmp1.size()]=tmp2[i];
        }
        return ;
    }
    vector<int> beautifulArray(int n) {
        vector<int>v(n);
        for(int i=1; i<=n; i++){
            v[i-1]=i;
        }
        solve(v);
        return v;
    }
};