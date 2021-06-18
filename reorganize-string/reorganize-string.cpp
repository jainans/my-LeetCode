class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        vector<pair<int, int> >v(26, {0, 0});
        for(int i=0; i<n; i++){
            int p = s[i]-'a';
            v[p].first++;
            v[p].second = p;
        }
        vector<char>ans(n, 'A');
        for(int i=0; i<26; i++){
            if(v[i].first>(n+1)/2)
                return "";
        }
        int cnt=0;
        sort(v.rbegin(), v.rend());
            
            int y=0;
            for(int j=0; j<n; j+=2){
                if(v[y].first==0){
                    y++;
                }
                char p= 'a'+v[y].second;
                    ans[j]=p;
                    v[y].first--;
            }
        for(int j=1; j<n; j+=2){
             if(v[y].first==0){
                    y++;
                }
                char p= 'a'+v[y].second;
                    ans[j]=p;
                    v[y].first--;
        }
        
        string hj ="";
        for(int i=0; i<n; i++){
            hj+=ans[i];
        }
            
        
        return hj;
    }
};