class MapSum {
private:
    unordered_map<string, int>mp;
    unordered_map<string, int>mp2;
public:
    /** Initialize your data structure here. */
    
    MapSum() {
        mp.clear();
        mp2.clear();
    }
    
    void insert(string key, int val) {
        if(mp2.find(key)!=mp2.end()){
            int p = val;
            val-=mp2[key];
            mp2[key]=p;
        }
        else
            mp2[key]=val;
        string p="";
        for(int i=0; i<key.size(); i++){
            p+=key[i];
            mp[p]+=val;
        }
    }
    
    int sum(string prefix) {
        return mp[prefix];
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */