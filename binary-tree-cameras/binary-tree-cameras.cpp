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
    vector<int> solve(TreeNode* root){
        if(root==NULL){
            vector<int>temp;
            temp.push_back(99999);
            temp.push_back(0);
            temp.push_back(0);
            return temp;
        }
        vector<int>lef = solve(root->left);
        vector<int>rit = solve(root->right);
        vector<int>ans(3);
        ans[0]=1+min(lef[0], min(lef[1], lef[2]))+min(rit[0], min(rit[1], rit[2]));
        ans[1] = min(lef[0]+min(rit[0], rit[1]), rit[0]+min(lef[0], lef[1]));
        ans[2] = lef[1]+rit[1];
        return ans;
    }
    int minCameraCover(TreeNode* root) {
        //three possibilities can arise
        //root has a camera and all its descendents are proctored
        //root doesn't have camera and all its descendent including it are proctored
        //root doesn't haave a  camera and all its descendents are proctored but not the root
        //we will use dp on trees to solve this qestion
        vector<int>ans = solve(root);
        return min(ans[0], ans[1]);
        
    }
};