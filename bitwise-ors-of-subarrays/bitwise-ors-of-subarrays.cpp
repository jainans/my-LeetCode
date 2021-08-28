class Solution {
public:
    int subarrayBitwiseORs(vector<int>& A) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(0);
        unordered_set<int> res, cur, cur2;
        for (int i: A) {
            cur2 = {i};
            for (int j: cur) cur2.insert(i|j);
            for (int j: cur = cur2) res.insert(j);
        }
        return res.size();
    }
};