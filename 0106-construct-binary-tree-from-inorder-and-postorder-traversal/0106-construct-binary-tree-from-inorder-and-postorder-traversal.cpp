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
unordered_map<int,int>m;
int idx;
TreeNode* built(vector<int>& inorder, vector<int>& postorder,int st,int end){
    if(st > end){
        return NULL;
    }
    int rootval = postorder[idx--];
    TreeNode* root = new TreeNode(rootval);
    int mid = m[rootval];
    root->right = built(inorder,postorder,mid+1,end);

    root->left = built(inorder,postorder,st,mid-1);
   
    return root;
}
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i=0;i<inorder.size();i++){
            m[inorder[i]] = i;
        }
        idx = postorder.size()-1;
        return built(inorder,postorder,0,inorder.size()-1);
    }
};