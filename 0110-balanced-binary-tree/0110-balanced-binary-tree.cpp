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
int h1(TreeNode*lef){
    if(lef == NULL){
        return 0;
    }
    int l = h1(lef->left);
    int r = h1(lef->right);
    return max(l,r)+1;
}
int h2(TreeNode*righ){
    if(righ == NULL){
        return 0;
    }
    int l = h1(righ->left);
    int r = h1(righ->right);
    return max(r,l)+1;
}
    bool isBalanced(TreeNode* root) {
        if(root == NULL){
            return true;
        }
        TreeNode*lef = root->left;
        TreeNode*righ = root->right;
        int m = h1(lef);
        int n = h2(righ);
        if(abs(m-n)>1){
            return false;
        }
        return isBalanced(root->left) && isBalanced(root->right);
    }
};