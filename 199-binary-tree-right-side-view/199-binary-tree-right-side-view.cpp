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
    
    void dfs(TreeNode *root, int lvl, vector<int> &ans) {
        if(!root) return;
        if(lvl == ans.size()) ans.push_back(root->val);
        dfs(root->right, lvl+1, ans);
        dfs(root->left, lvl+1, ans);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        dfs(root, 0, ans);
        return ans;
    }
};

// class Solution {
// public:
//     vector<int> rightSideView(TreeNode* root) {
//         vector<int> ans;
//         if(!root) return ans;
        
//         queue<TreeNode*> q;
//         q.push(root);
        
//         while(!q.empty()) {
//             int n = q.size();
//             for(int i=0; i<n; i++) {
//                 TreeNode* cur = q.front();
//                 q.pop();
                
//                 if(i==n-1) ans.push_back(cur->val);
                
//                 if(cur->left) q.push(cur->left);
//                 if(cur->right) q.push(cur->right);
//             }
//         }
//         return ans;
//     }
// };