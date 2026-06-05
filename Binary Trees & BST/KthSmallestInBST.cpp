// Problem: Kth Smallest Element in BST
// https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/

// FOR BFS: https://takeuforward.org/data-structure/kth-largest-smallest-element-in-binary-search-tree

// Optimized: Using global variable and DFS Inorder Traversal
//TC: O(N), where N is the number of nodes in the binary tree. The reason is that in the worst-case scenario, the inorder and reverse inorder traversals visit each node exactly once.
// SC: O(H), where H is the height of the binary tree.

class Solution {
    int Ksmall;
public: 
    void inorderT(TreeNode* root, int& k)
    {
        if(root == NULL)
         return;
         inorderT(root->left, k);
         if (--k == 0) {
         Ksmall = root->val;
         return;
        }
         inorderT(root->right, k);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        if(root == NULL)
         return 0;
         
        inorderT(root, k);
        return Ksmall;    
    }
};
