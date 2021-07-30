class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int  n = nums1.size();
        int m = nums2.size();
        if(n>m)
            return findMedianSortedArrays(nums2, nums1);
        if(n==0){
            if(m%2==0)
            {
                double d = (nums2[m/2-1]+nums2[m/2])*1.0/2;
                return d;
            }
            else
                return nums2[m/2];
        }
        int l=0;
        int r = n;
        while(l<=r){
            int mid = l+(r-l)/2;
            int p = (n+m)/2;
            int q = p-mid;
            if(q>m)
            {
                l=mid+1;
                continue;
            }
            int minm1 = (mid==0) ? INT_MIN : nums1[mid-1];
            int minm2  = (q==0) ? INT_MIN : nums2[q-1];
            int max1 = (mid==n) ? INT_MAX : nums1[mid];
            int max2 = (q==m) ? INT_MAX : nums2[q];
            if(max(minm1, minm2)<=min(max1, max2)){
                if((n+m)%2==0){
                    double d = (max(minm1, minm2)+min(max1, max2))*1.0/2;
                    return d;
                }
                else
                    return min(max1, max2);
            }
            else if(minm1>max2){
                r=mid-1;
            }
            else if(minm2>max1)
                l=mid+1;
        }
        return -1;
    }
};