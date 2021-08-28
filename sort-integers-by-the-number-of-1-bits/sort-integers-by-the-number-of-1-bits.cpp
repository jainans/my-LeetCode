bool comp(int a, int b){
    int c = __builtin_popcount(a);
    int d = __builtin_popcount(b);
    if(c<d)
        return true;
    if(c==d){
        return (a<=b);
    }
    return false;
}
class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), comp);
        return arr;
    }
};