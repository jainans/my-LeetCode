class Solution {
public:
    bool isPossible(vector<int>& nums) {
        // very good problem 
        // we will take 3 pointers 
        // p1 = no. of subsets of length 1 with curr-1 as end
        //p2 =no. of subsets of length 2 with curr-1 as end
        //p3 =no. of subsets of length >=3 with curr-1 as end
        
        // we will update these values as we will go through
        // let's say cnt = no. of elements of curr element
        // if(curr!=prev+1)
        // if(p1!=0 || p2!=0 )not possible
        // else c1 = cnt, c2=0, c3=0
        // if(curr==prev+1)
        // cnt should be >= p1+p2
        // c2 = p1;
        //c3 = p2+min(cnt-p1-p2, p3);
        // c1= max(0, cnt-p1-p2-p3)
        int prev = -10000;
        int p1=0;
        int p2=0;
        int p3=0;
        int curr = nums[0];
        int cnt=0;
        int c1,c2,c3;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==curr)
                cnt++;
            else{
                if(curr!=prev+1){
                    if(p1!=0 || p2!=0)
                        return false;
                    c1 = cnt;
                    c2=0;
                    c3=0;
                    prev  = curr;
                    p1=c1;
                    p2=c2;
                    p3=c3;
                    curr  = nums[i];
                    cnt=1;
                }
                else{
                    if(cnt<p1+p2)
                        return false;
                    c1 = max(0, cnt-p1-p2-p3);
                    c2= p1;
                    c3 =p2+min(cnt-p1-p2, p3);
                    prev = curr;
                    p1=c1;
                    p2=c2;
                    p3=c3;
                    curr = nums[i];
                    cnt=1;
                }
            }
        }
         if(curr!=prev+1){
                    if(p1!=0 || p2!=0)
                        return false;
                    c1 = cnt;
                    c2=0;
                    c3=0;
                    prev  = curr;
                    p1=c1;
                    p2=c2;
                    p3=c3;
                   
                    
                }
                else{
                    if(cnt<p1+p2)
                        return false;
                    c1 = max(0, cnt-p1-p2-p3);
                    c2= p1;
                    c3 =p2+min(cnt-p1-p2, p3);
                    prev = curr;
                    p1=c1;
                    p2=c2;
                    p3=c3;
                    
                }
        if(p1!=0 || p2!=0)
            return false;
        return true;
        
    }
};