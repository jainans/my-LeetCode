class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        int l = -1;
        int r = 0;
        while(r<n){
            if(dominoes[r]!='.'){
            while(r<n && dominoes[r]!='.'){
                l = r;
                r++;
            }
            }
            else{
               while(r<n && dominoes[r]=='.')
                  r++;
               if(r==n && l==-1)
                   break;
                if(l==-1){
                    if(dominoes[r]=='L'){
                    for(int i=l+1; i<r; i++){
                        dominoes[i]=dominoes[r];
                    }
                    } 
                }
                else if(r==n){
                    if(dominoes[l]=='R'){
                    for(int i=l+1; i<r; i++)
                        dominoes[i]=dominoes[l];
                    }
                }
                else{
                    int k= (r-l-1)/2;
                    if(dominoes[l]=='R' && dominoes[r]=='L'){
                    for(int i=l+1; i<l+1+k; i++)
                        dominoes[i]=dominoes[l];

                    for(int i=r-1; i>r-k-1; i--)
                        dominoes[i]=dominoes[r];
                    }
                    else if(dominoes[l]=='R'){
                        for(int i=l+1; i<r; i++)
                            dominoes[i]='R';
                    }
                    else if(dominoes[r]=='L'){
                        for(int i=l+1; i<r; i++)
                            dominoes[i]='L';
                    }
                }
                l=r;
            }
        }
        return dominoes;
        
    }
};