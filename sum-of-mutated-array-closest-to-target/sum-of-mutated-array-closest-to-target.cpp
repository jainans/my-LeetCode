class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        int maxo = INT_MIN;
        int n = arr.size();
        for(int i=0; i<n; i++){
            maxo = max(maxo, arr[i]);
        }
        int l=0;
        int r = maxo;
        int nas;
        int diff = INT_MAX;
        while(l<=r){
            int mid = l+(r-l)/2;
            int sum=0;
            for(int i=0; i<n; i++){
                sum+=(arr[i]>mid) ? mid : arr[i];
            }
            if(sum<target){
                l = mid+1;
                if(abs(target-sum)<=diff){
                    diff = abs(target-sum);
                    nas = mid;
                }
            }
            else{
                r = mid-1;
                if(abs(target-sum)<diff){
                    diff = abs(target-sum);
                    nas = mid;
                }
            }
        }
        return nas;
    }
};