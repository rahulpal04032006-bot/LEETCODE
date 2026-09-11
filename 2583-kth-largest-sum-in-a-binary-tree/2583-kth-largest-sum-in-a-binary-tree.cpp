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
long long sum = 0;
vector<long long>ans;
void level(TreeNode* root){
    queue<TreeNode*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        TreeNode* curr = q.front();
        q.pop();
        if(curr == NULL){
            ans.push_back(sum);
            sum = 0;
            if(q.empty()){
                break;
            }
            q.push(NULL);
        }else{
            sum += curr->val;
            if(curr->left != NULL){
                q.push(curr->left);
            }
            if(curr->right != NULL){
        q.push(curr->right);
            }
        }
    }
    sort(ans.begin(),ans.end());
}
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if(root == NULL)
            return -1;
        
        level(root);
        int n = ans.size();
        if(k > n){
            return -1;
        }
        return ans[n-k];
    }
};