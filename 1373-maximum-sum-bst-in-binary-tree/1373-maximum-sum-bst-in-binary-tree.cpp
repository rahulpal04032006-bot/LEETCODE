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
    struct Info {
        bool isBST;
        int Min;
        int Max;
        int sum;

        Info(bool isBST, int Min, int Max, int sum) {
            this->isBST = isBST;
            this->Min = Min;
            this->Max = Max;
            this->sum = sum;
        }
    };
int maxsum;
Info* largest(TreeNode* root){
    if(root == NULL){
        return new Info(true,INT_MAX,INT_MIN,0);
    }
    Info* leftinfo = largest(root->left);
    Info* rightinfo = largest(root->right);
    int currMin = min(root->val,min(leftinfo->Min,rightinfo->Min));
    int currMax = max(root->val,max(leftinfo->Max,rightinfo->Max));
    int sum = leftinfo->sum + rightinfo->sum + root->val;
    if(leftinfo->isBST && rightinfo->isBST && root->val > leftinfo->Max && root->val < rightinfo->Min){
        maxsum = max(maxsum,sum);
        return new Info(true,currMin,currMax,sum);
    }
    return  new Info(false,currMin,currMax,sum);
}

    int maxSumBST(TreeNode* root) {
        maxsum = 0;
      largest(root);
      return maxsum;
    }
};