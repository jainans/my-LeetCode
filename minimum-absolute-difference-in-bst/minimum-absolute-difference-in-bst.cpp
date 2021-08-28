/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        stack<TreeNode* >st;
        int pre  = -1e5;
        int ans=  INT_MAX;
        TreeNode* curr =root;
        while(1){
            while(curr){
                st.push(curr);
                curr = curr->left;
            }
            if(st.empty())
                break;
            ans = min(ans, abs(pre-st.top()->val));
            pre = st.top()->val;
            curr = st.top()->right;
            st.pop();
            
        }
        return ans;
    }
};