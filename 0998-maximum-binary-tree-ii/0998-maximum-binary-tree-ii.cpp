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
// void inorder(TreeNode* root,vector<TreeNode*>& a){
//     if(root == NULL){
//         return;
//     }
//     inorder(root->left,a);
//     a.push_back(root);
//     inorder(root->right,a);
// }
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        if(root == NULL){
            return new TreeNode(val);
        }
        if(val > root->val){
            TreeNode* newNode = new TreeNode(val);
            newNode->left = root;
            root = newNode;
            return root;
        }else{
            root->right = insertIntoMaxTree(root->right,val);
            return root;
        }
        

    }
};