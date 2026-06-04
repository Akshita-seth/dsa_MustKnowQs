// Problem: LCA in BST
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

//       Generic Binary Tree LCA	                BST-Based LCA
// TC:      𝑂(𝑁)                                       O(H)
// SC:     𝑂(H)                                        O(1)

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
