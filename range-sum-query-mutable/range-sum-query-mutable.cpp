class NumArray {
public:
    vector<int> arr;
    vector<int> bitArr;
    NumArray(vector<int>& nums) {
        
        bitArr = vector<int>(nums.size(), 0);
        arr = bitArr;
        for(int i=0; i<nums.size(); i++){
            update(i, nums[i]);
        }
    }
    void update(int index, int val) {
        int p =  val-arr[index];
        arr[index] = val;
        int id = index+1;
        while(id<=bitArr.size()){
            bitArr[id-1]+=p;
            id+=((id) & (-id));
        }
    }
    int sumRange(int left, int right) {
        int sumr=0;
        int suml=0;
        int rt = right+1;
        int lt = left;
        while(rt){
            sumr+=bitArr[rt-1];
            rt-=(rt & (-rt));
        }
        while(lt){
            suml+=bitArr[lt-1];
            lt-=(lt & (-lt));
        }
        
        return sumr-suml;  
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */