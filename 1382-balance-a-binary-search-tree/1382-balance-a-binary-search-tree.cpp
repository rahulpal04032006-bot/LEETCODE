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
TreeNode* cons(vector<int>& temp,int st,int end){
    if(st > end){
        return NULL;
    }
    int mid = st + (end - st)/2;
    TreeNode* root = new TreeNode(temp[mid]);
    root->left = cons(temp,st,mid-1);
    root->right = cons(temp,mid+1,end);
    return root;
}
void inorder(TreeNode* root,vector<int>& temp){
    if(root == NULL){
        return;
    }
    inorder(root->left,temp);
    temp.push_back(root->val);
    inorder(root->right,temp);

}
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>temp;
        inorder(root,temp);
     return cons(temp,0,temp.size()-1);
    }
};