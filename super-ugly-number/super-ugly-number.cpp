class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        priority_queue<int, vector<int>, greater<int> >pq;
        sort(primes.begin(), primes.end());
        unordered_map<int, int>mp;
        mp[1]=1;
        for(int i=0; i<primes.size(); i++){
            pq.push(primes[i]);
            mp[primes[i]]=1;
        }
        if(n==1)
            return 1;
        for(int i=1; i<n-1; i++){
            int p = pq.top();
            pq.pop();
            for(int j=0; j<primes.size(); j++){
                long long int q = p*1LL*primes[j];
                if(q>INT_MAX)
                    break;
            if(mp[q]==0){
            pq.push(primes[j]*p);
            mp[primes[j]*p]=1;
            }
                
            }
            
        }
        return pq.top();
    }
    
};