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
    TreeNode* prev = NULL;
public:
        
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        if(!isValidBST(root->left)) return false;
        if(prev && prev->val >= root->val) return false;
        prev = root;
        return isValidBST(root->right);
    }
};

// class Solution {
// public:
//     bool isValid(TreeNode* root, long minVal, long maxVal) {
//         if(!root) return true;
//         if(root->val <= minVal || root->val >= maxVal) return false;
//         return isValid(root->left, minVal, root->val) && isValid(root->right, root->val, maxVal);
//     }
    
//     bool isValidBST(TreeNode* root) {
//         return isValid(root, LONG_MIN, LONG_MAX);
//     }
// };