class Solution {
public:
    //we will first reduce the problem to find max subarray sum in an 1D array in n*logn time using set
    int maxSumArray(vector<int>& arr, int k){
        int n = arr.size();
        int maxo = INT_MIN;
        int mxt = 0;
        for(int i=0; i<n; i++){
            if(arr[i]>mxt+arr[i])
                mxt = arr[i];
            else
                mxt+=arr[i];
            maxo=max(maxo, mxt);
        }
        if(maxo<=k)
            return maxo;
        else{
            set<int>st;
            st.insert(0);
            int sum=0;
            int ansd=INT_MIN;
            for(int i=0; i<n; i++){
                sum+=arr[i];
                int req = sum-k;
                auto it = st.lower_bound(req);
                if(it!=st.end()){
                    int p = *it;
                    ansd = max(ansd, sum-p);
                }
                st.insert(sum);
            }
            return ansd;
        }
    }
    int solve(vector<vector<int>>& mat, int n, int m, int k){
        vector<int>temp;
        int ans = INT_MIN;
        for(int i=0; i<n; i++){
            temp = mat[i];
            ans = max(ans, maxSumArray(temp, k));
            for(int j=i+1; j<n; j++){
                for(int k=0; k<m; k++)
                    temp[k]+=mat[j][k];
                ans = max(ans, maxSumArray(temp, k));
            }
        }
        return ans;
    }
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        //basic brute force will be to store sum of all rectangles ending at index {i, j}
        //then go for each rectangle and find its sum in O(1)
        // there will be total m^2*n^2 rectangles 
        //so brute force complexity will be of O(m^2*n^2)
        //improve it by going from row to row or either from coulmnn to coulmn
        return solve(matrix, matrix.size(), matrix[0].size(), k);
    }
};