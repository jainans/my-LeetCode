class Solution {
public:
    vector<int> arr;
    vector<int> original;
    Solution(vector<int>& nums) {
        arr = nums;
       original=nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return original;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        int random;
       for(int i=0; i<arr.size(); i++){
           random  = i+ (rand())%(arr.size()-i);
           swap(arr[random], arr[i]);
       }
        return arr;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */