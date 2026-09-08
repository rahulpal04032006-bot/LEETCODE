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
TreeNode* build(vector<int>& preorder, vector<int>& postorder,int prest,int preend,int postst,int postend){
    if(prest == preend){
        return new TreeNode(preorder[prest]);
    }
    TreeNode* root = new TreeNode(preorder[prest]);
    int leftroot = preorder[prest+1];
    int idx;
    for(int i = postst;i<=postend;i++){
        if(leftroot == postorder[i]){
            idx = i;
            break;
        }
    }
    int leftsubtreesize = idx - postst + 1;
    if (leftsubtreesize > 0){
         root->left = build(preorder,postorder,prest+1,prest+leftsubtreesize,postst,idx-1);
    }
   if (prest + leftsubtreesize + 1 <= preend){
    root->right = build(preorder,postorder,prest+leftsubtreesize+1,preend,idx+1,postend);
   }
    return root;
}
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int m = preorder.size();
        int n = postorder.size();
        return build(preorder,postorder,0,m-1,0,n-1);
    }
};