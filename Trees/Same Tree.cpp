class Solution {
    public:
        bool isSameTree(TreeNode* p, TreeNode* q) {
            // Both nodes are null
            if (!p && !q) return true;
    
            // One is null or values do not match
            if (!p || !q || p->val != q->val) return false;
    
            // Recursively check left and right subtrees
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }
    };
    