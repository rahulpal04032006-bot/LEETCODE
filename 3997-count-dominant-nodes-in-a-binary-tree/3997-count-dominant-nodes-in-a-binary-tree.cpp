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
int postorder(TreeNode* root, int& count){
    if(root == NULL){
        return INT_MIN;
    }
    int left = postorder(root->left,count);
    int right = postorder(root->right,count);
    int subtreemax = max(root->val, max(left,right));
        if(root->val >= max(left,right)){
            count++;
        }
        return subtreemax;
}
    int countDominantNodes(TreeNode* root) {
        int count = 0;
        postorder(root,count);
       return count;
    }
};