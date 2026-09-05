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
vector<vector<int>>ans;
vector<int>temp;
void level(TreeNode* root,int currlevel){
    if(root == NULL){
        return;
    }
    queue<TreeNode*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        TreeNode* curr = q.front();
        q.pop();
        if(curr == NULL){
            if(currlevel % 2 == 0){
                reverse(temp.begin(),temp.end());
            }
            ans.push_back(temp);
            temp.clear();
            currlevel++;
            if(q.empty()){
                break;
            }
            q.push(NULL);
        }else{
            temp.push_back(curr->val);
            if(curr->left != NULL){
                q.push(curr->left);
            }
            if(curr->right != NULL){
                q.push(curr->right);
            }
          
        }
    }

}
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
       
        level(root,1);
        return ans;
    }
};