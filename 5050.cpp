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
    int index = 0;
    
    void traverseBST(TreeNode* root, vector<int>& array){
        if(root != NULL){
            traverseBST(root->left, array);
            array.push_back(root->val);
            traverseBST(root->right, array);
        }
    }
    
    void traverseAndReplaceBST(TreeNode* root, vector<int>& array){
        if(root != NULL){
            traverseAndReplaceBST(root->left, array);
            root->val = array[index];
            index++;
            traverseAndReplaceBST(root->right, array);
        }
    }
    
    TreeNode* bstToGst(TreeNode* root) {
        vector<int> sorted = vector<int>();
        traverseBST(root, sorted);
        
        int sum = 0;
        for(int i = sorted.size() - 1; i >= 0; i--){
            // cout << sorted[i] << endl;
            sum += sorted[i];
            sorted[i] = sum;
        }
        
        traverseAndReplaceBST(root, sorted);
        
        return root;
    }
};
