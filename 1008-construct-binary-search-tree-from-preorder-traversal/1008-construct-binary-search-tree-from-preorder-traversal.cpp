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
TreeNode* preorder1(vector<int>& nums,int st,int end){
    if(st > end){
        return NULL;
    }
    TreeNode* root = new TreeNode(nums[st]);
   int rootval = nums[st];
   int idx = end+1;
   for(int i=st+1;i<=end;i++){
    if(nums[i] > rootval){
        idx = i;
        break;
    }
   }
    root->left = preorder1(nums,st+1,idx-1);
    root->right = preorder1(nums,idx,end);
    return root;
}
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return preorder1(preorder,0,preorder.size()-1);
       
    }
};