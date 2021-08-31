class Solution {
public:
    int numRabbits(vector<int>& answers) {
        sort(answers.begin(), answers.end());
        int curr = -1;
        int freq = 0;
        int n = answers.size();
        int p=0;
        int q;
        for(int i=0; i<n; i++){
            if(answers[i]!=curr){
                if(curr+1!=0){
                    q = freq/(curr+1) + ((freq%(curr+1)!=0) ? 1 : 0);
                    p+=q*(curr+1);  
                }
                curr = answers[i];
                freq=1;
                
                
            }
            else{
                freq++;
            }
        }
        q = freq/(curr+1) + ((freq%(curr+1)!=0) ? 1 : 0);
        p+=q*(curr+1);  
        return p;
    }
};