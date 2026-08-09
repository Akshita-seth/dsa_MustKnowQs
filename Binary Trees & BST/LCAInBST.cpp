// Problem: LCA in BST
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

//       Generic Binary Tree LCA	 BST based Recursive                BST-BasedIterative
// TC:      𝑂(𝑁)                       O(H)                                     O(H)
// SC:     𝑂(H)                         O(H)                                    O(1)

// Better than generic BT soln:
// Using BST properties recursively


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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL || root == p || root == q)
        return root;

        if(p->val < root->val && q->val < root->val)
        return lowestCommonAncestor(root->left, p, q);

        else if(p->val > root->val && q->val > root->val)
        return lowestCommonAncestor(root->right, p, q);
        
        else 
        return root;
    }
};


// Optimized: Using BST Properties Iteratively

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while(root)
        {
            if(p->val < root->val && q->val < root->val)
            root = root->left;

            else if(p->val > root->val && q->val > root->val)
            root = root->right;

            else    //(root == p || root == q) OR p and q in different trees
           return root; //then also root only lca  

        }
        return NULL;
    }
};
