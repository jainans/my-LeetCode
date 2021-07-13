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
    int kthSmallest(TreeNode* root, int k) {
       stack<TreeNode* >st;
        int p=0;
        while(1){
           while(root){
               st.push(root);
               root = root->left;
           }
            if(st.empty())
                break;
            p++;
            if(p==k){
                return st.top()->val;
            }
            root = st.top()->right;
            st.pop();
        }
        return 0;
    }
};