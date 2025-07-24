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
        int maxDepth(TreeNode* root) {
         if (!root) return 0;
    
        queue<TreeNode*> q;
        q.push(root);
        int height = 0;
    
        while (!q.empty()) {
            int levelSize = q.size();  // Number of nodes at current level
    
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* curr = q.front();
                q.pop();
    
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
    
            height++; // Completed one level
        }
    
        return height;
        }
    };



//recursive solution
class Solution {
    public:
        int maxDepth(TreeNode* root) {
            if (!root) return 0;
            int leftDepth = maxDepth(root->left);
            int rightDepth = maxDepth(root->right);
            // Return the maximum depth of the left or right subtree plus one for the current node

            return 1 + max(leftDepth, rightDepth);
};    