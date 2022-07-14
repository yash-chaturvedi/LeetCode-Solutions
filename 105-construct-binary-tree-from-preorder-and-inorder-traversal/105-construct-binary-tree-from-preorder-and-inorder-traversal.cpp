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
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, unordered_map<int, int> &mp, 
                        int inStart, int inEnd, int preStart) {
        
        if(inStart > inEnd) return NULL;
        
        int rootIdx = mp[preorder[preStart]];
        int leftSize = rootIdx - inStart;
        TreeNode *root = new TreeNode(inorder[rootIdx]);
        root->left = buildTree(preorder, inorder, mp, inStart, rootIdx-1, preStart+1);
        root->right = buildTree(preorder, inorder, mp, rootIdx+1, inEnd, preStart+leftSize+1);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mp;
        int n = inorder.size();
        for(int i=0; i<n; i++) {
            mp[inorder[i]] = i;
        }
        return buildTree(preorder, inorder, mp, 0, n-1, 0);
    }
};