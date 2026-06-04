// Problem: Diameter of BT
// The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.
// https://leetcode.com/problems/diameter-of-binary-tree/description/
// https://takeuforward.org/data-structure/calculate-the-diameter-of-a-binary-tree


// Why not +1 in diaam calculation
// In height calculation, we add +1 because we’re counting the current node itself.
// In diameter calculation, we don’t add +1 because diameter is measured in edges, not nodes.
// If you added +1, you’d be overcounting — you’d be treating diameter as “nodes on the path” instead of “edges.”

// BFS: Recursive approacch. Calculating the max depth of both left and right subtrees at each node and treating each node as a turning point. Hence, the max diameter is LH + RH + 1, 1 for the turning point node.
// TC: O(N*N) where N is the number of nodes in the Binary Tree.
// The extra time is because it keeps recalculating the depth of subtrees again and again.
// SC: O(1)

class Solution {
    int maxi=0;
public:
    int findHeight(TreeNode* root)
    {
        if(root == NULL)
        return 0;
        int lh = findHeight(root->left);
        int rh = findHeight(root->right);
        return 1+max(lh,rh);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL)
        return 0;

        int lh = findHeight(root->left);
        int rh = findHeight(root->right);
        
        maxi = max(maxi, lh+rh);

        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);
        return maxi;
    }
};


//Optimized:
// TC: O(N) 
// SC: Recursion stack space only

class Solution {
    // int diam = 0; //either keep diam as a global variable or do like below, i.e. pass by reference so that modification happens in the original diam variable
public: 
    int height(TreeNode* root, int& diam)
    {
        if(root == NULL)
        return 0;
        int lh=height(root->left,diam);
        int rh=height(root->right,diam);
        diam = max(diam,lh+rh);
        return 1+max(lh,rh);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diam=0;
        height(root,diam);
        return diam;
    }
};

class Solution {
    int diam = 0;
public:
    int findHeight(TreeNode* root)
    {
        if(root == NULL)
        return 0;
        int lh = findHeight(root->left);
        int rh = findHeight(root->right);
        diam = max(diam, lh+rh);
        return 1 + max(lh, rh);  // Although no variable to accept the return value in calling fn, the return statement is imp for recusrion of the findheight()
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL)
        return 0;
        findHeight(root);
        return diam;
    }
};
