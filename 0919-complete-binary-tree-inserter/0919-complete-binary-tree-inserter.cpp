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
class CBTInserter {
public:
vector<TreeNode*>nums;
    CBTInserter(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            nums.push_back(curr);
            if(curr->left != NULL){
                q.push(curr->left);
            }
            if(curr->right != NULL){
                q.push(curr->right);
            }
        }
    }
    
    int insert(int val) {
        TreeNode* newNode = new TreeNode(val);
        nums.push_back(newNode);
        int x = nums.size() - 1;
        int parent = (x-1)/2;
        if(x%2 == 1){
            nums[parent]->left = newNode;
        }else{
            nums[parent]->right = newNode;
        }
        return nums[parent]->val;
    }
    
    TreeNode* get_root() {
      return  nums[0];
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */