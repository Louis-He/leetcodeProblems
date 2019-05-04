/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* current = root;
        while(current != NULL){
            if(current->val == val){
                return current;
            }else if(current->val > val){
                current = current->left;
            }else{
                current = current->right;
            }
        }
        
        return NULL;
    }
};
