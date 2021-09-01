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
    int mcnt;
    int maxo;
    void inorder(TreeNode* root, int & cnt){
        if(root){
            cnt++;
            inorder(root->left, cnt);
            if(cnt>mcnt){
                mcnt=cnt;
                maxo = root->val;
            }
            cnt--;
            cnt++;
            inorder(root->right, cnt);
            cnt--;
        }
    }
    int findBottomLeftValue(TreeNode* root) {
        mcnt=-2;
        int cnt=0;
        inorder(root, cnt);
        return maxo;
    }
};