// Problem: Validate BST
// https://leetcode.com/problems/validate-binary-search-tree/

// BFS: Do an inorder traversal, store all values in a list, then check if the list is strictly increasing 
// TC: O(N) SC: O(N)

// Optimized: Use recursion (or BFS with bounds), carrying min/max constraints down the tree, validating each node on the fly 
// The optimized recursion works because each node is checked against its global bounds, not just its parent.
// TC: O(N) SC: O(H)

class Solution {
public: 
    bool validate(TreeNode* node, long min, long max)
    {
       if(node == nullptr)
       return true;
       if(node->val <= min || node->val >= max)
       return false;
       return validate(node->left, min, node->val) &&
       validate(node->right, node->val, max);
    }
public:
    bool isValidBST(TreeNode* root) {
        if(root == NULL)
        return true;

        return validate(root, LONG_MIN, LONG_MAX);
    }
};
