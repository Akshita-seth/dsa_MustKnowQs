// Problem: Maximum Depth of a Binary tree
// A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
// https://leetcode.com/problems/maximum-depth-of-binary-tree/description/

//RECURSIVE 
// TC: O(N)
// SC: O(height of tree), i.e. O(N) worst case, O(log N) best case for balanced trees.

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr)
        return 0;
        int lh=maxDepth(root->left);
        int rh=maxDepth(root->right);
        return 1+max(lh,rh);
    }
};

//Level Order Traversal Method
// TC: O(N) Every node is enqueued and dequeued once → O(2N).
// SC: O(N) Worst Case if complete BTand O(width of tree), (width is less than N) if balanced tree

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL)
        return 0;
        int depth = 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int size = q.size();
            for(int i=0; i< size; i++)
            {
                TreeNode* node= q.front();
                q.pop();
                if(node->left)
                q.push(node->left);
                if(node->right)
                q.push(node->right);
            }
            depth++;
        }
        return depth;
    }
};
