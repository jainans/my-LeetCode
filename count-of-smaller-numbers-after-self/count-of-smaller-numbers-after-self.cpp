class Solution {
public:
    
    
    void merge(int l, int mid, int r, vector<pair<int, int> >& nums){
        int ls = mid-l+1;
        int rs = r-mid;
        auto * leftArray = new pair<int, int>[ls];
        auto * rightArray = new pair<int, int>[rs];
        for(int i=0; i<ls; i++){
            leftArray[i] = nums[l+i];
        }
        for(int i=0; i<rs; i++){
            rightArray[i]= nums[mid+1+i];
        }
        int p=0;
        int q=0;
        int rr= l;
        while(p<ls && q<rs){
            if(leftArray[p].first<=rightArray[q].first){
                nums[rr] = leftArray[p];
                rr++;
                p++;
            }
            else{
                nums[rr] = rightArray[q];
                rr++;
                q++;
            }
        }
        while(p<ls){
             nums[rr] = leftArray[p];
                rr++;
                p++;
        }
        while(q<rs){
             nums[rr] = rightArray[q];
                rr++;
                q++;
        }
    }
    void mergeSort(int l, int r, vector<pair<int, int> >& nums, vector<int>& ans){
        if(l>=r)
            return;
        int mid = l+(r-l)/2;
        mergeSort(l, mid, nums, ans);
        mergeSort(mid+1, r, nums, ans);
        int q = mid+1;
        for(int i=l; i<=mid; i++){
            while(q<=r && nums[q].first<nums[i].first)
                q++;
           ans[nums[i].second]+= q-1-mid;
        }
        merge(l, mid, r, nums);
    }
    vector<int> countSmaller(vector<int>& nums) {
        vector<pair<int, int> >v;
        vector<int>ans(nums.size(), 0);
        for(int i=0; i<nums.size(); i++){
            v.push_back({nums[i], i});
        }
       mergeSort(0, v.size()-1, v, ans);
        return ans;
    }
};