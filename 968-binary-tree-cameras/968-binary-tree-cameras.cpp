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
    
    int dfs(TreeNode *root, int &ans) {
        if(!root) return 2;
        
        int l = dfs(root->left, ans);
        int r = dfs(root->right, ans);
        
        if(l==0 || r==0) {
            ans++;
            return 1;
        }
        
        if(l==1 || r==1) {
            return 2;
        }
        
        return 0;
    }
    
public:
    int minCameraCover(TreeNode* root) {
        int ans = 0;
        if(dfs(root, ans) == 0) ans++;
        return ans;
    }
};