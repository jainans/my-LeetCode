class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        unordered_map<int, int>mp;
        
        int cnt=0;
        for(int i=arr.size()-1; i>=0; i--){
            if(arr[i]<0)
                break;
            if(mp.find(2*arr[i])==mp.end() || mp[2*arr[i]]==0){
                mp[arr[i]]++;
            }
                
            else{
               
                 cnt++;
                mp[2*arr[i]]--;
            }
        }
        int i=0;
        while(i<arr.size() && arr[i]<0){
             if(mp.find(2*arr[i])==mp.end() || mp[2*arr[i]]==0){
                mp[arr[i]]++;
            }
                
            else{
               
                 cnt++;
                mp[2*arr[i]]--;
            }
            i++;
        }
        if(cnt==arr.size()/2)
            return true;
        return false;
    }
};