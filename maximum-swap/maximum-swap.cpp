class Solution {
public:
    int maximumSwap(int num) {
        if(num<=11)
            return num;
        vector<int>dig;
        while(num){
            dig.push_back(num%10);
            num/=10;
        }
        reverse(dig.begin(), dig.end());
        int n = dig.size();
        vector<int>maxo(n);
        maxo[n-1]=n-1;
        for(int i=n-2; i>=0; i--){
            if(dig[i]>dig[maxo[i+1]])
                maxo[i]=i;
            else
                maxo[i] = maxo[i+1];
        }
        for(int i=0; i<n-1; i++){
            if(dig[maxo[i+1]]>dig[i]){
                swap(dig[maxo[i+1]], dig[i]);
                break;
            }
        }
        int ans=0;
        for(int i=0; i<n; i++){
            ans = 10*ans+dig[i];
        }
        return ans;
    }
};