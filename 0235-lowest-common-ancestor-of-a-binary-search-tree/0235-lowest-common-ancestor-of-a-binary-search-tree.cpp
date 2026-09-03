/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
TreeNode* lca(TreeNode* root,TreeNode*p,TreeNode* q){
    if(root == NULL){
        return NULL;
    }
    if(root == p || root == q){
        return root;
    }
    TreeNode* leftroot = lca(root->left,p,q);
    TreeNode* rightroot = lca(root->right,p,q);
    if(leftroot != NULL && rightroot != NULL){
        return root;
    }
    return leftroot == NULL?rightroot:leftroot;
}
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       return lca(root,p,q);
      
    }
};