
class Solution {
public:
    int find(int node, vector<int>& par){
        if(par[node]==node)
            return node;
        return par[node]= find(par[node], par);
    }
    void join(int x, int y, vector<int>& par){
        x=find(x, par);
        y = find(y, par);
        if(x!=y)
            par[x]=y;
    }
    
    
    bool gcdSort(vector<int>& nums) {
        vector<int> par(100001);
        for(int i=0; i<=100000; i++)
            par[i]=i;
       int n = nums.size();
        vector<int>fst(n, -1);
       vector<pair<int, int> >v(n);
        for(int i=0; i<n; i++){
            v[i]={nums[i], i};
        }
        sort(v.begin(), v.end());
        
        
        
        for(int i=0; i<nums.size(); i++){
            int prev =-1;
            int q = nums[i];
            if(q%2==0){
                fst[i]=2;
                prev=2;
                while(q%2==0)
                    q/=2;
            }
            for(int j=3; j*j<=q; j+=2){
                if(q%j==0){
                    if(fst[i]==-1)
                        fst[i]=j;
                    if(prev!=-1)
                    join(prev, j, par);
                    prev=j;
                    while(q%j==0)
                        q/=j;
                }
            }
            if(q>1){
                if(fst[i]==-1)
                    fst[i]=q;
                if(prev!=-1)
                    join(prev, q, par);
            }
        }
     
        for(int i=0; i<n; i++){
            if(find(fst[i], par)!= find(fst[v[i].second], par))
                return false;
        }
        return true;
    }
};