// Problem: Lowest Common Ancestor In A Binary Tree
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/


// TC: O(N), where N is the number of nodes in the binary tree. In the worst case, we may need to traverse all nodes to find the LCA.
// SC: O(H), where H is the height of the binary tree. This is due to the recursive stack space used during the traversal. In the worst case, for a skewed tree, H can be equal to N, but for a balanced tree, H will be log(N).


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //BAse CAse
        if(root == NULL || root == p || root == q)
        return root;
        //search in left and right subtrees
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        // Both left and right are not null, we found our result
        if(left && right)
        return root;
        else if(left)
        return left;
        else if(right)
        return right;
        return NULL;
    }
};

// SAME BUT DIFFERENT STYLE

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(root == NULL || root == p || root == q) return root;
        
        TreeNode* left= lowestCommonAncestor(root->left, p, q);
        TreeNode* right= lowestCommonAncestor(root->right, p, q);

        if(left == NULL) return right;
        else if(right == NULL) return left;
        else return root;

       //if (left && right) return root;
       // return left? left: right;
    }
};
