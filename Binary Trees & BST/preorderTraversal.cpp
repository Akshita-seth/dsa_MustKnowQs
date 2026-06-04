// Problem: Binary Tree DFS Traversal -> PREORDER
// https://leetcode.com/problems/binary-tree-preorder-traversal/


// Recursive:
// TC: O(N) [N=No. of nodes] bcz each node is visited once
// SC: O(Height of Tree) due to recursion stack. In the worst case (skewed tree), height = N → SC = O(N).
// In best case (balanced tree), height = log N → SC = O(log N). 

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
public:
    void preorder(TreeNode* root, vector<int>& arr)
    {
        if(root==nullptr)
        return;
        arr.push_back(root->val);
        inorder(root->left,arr);
        inorder(root->right,arr);
    }
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> arr;
        preorder(root,arr);
        return arr;
    }
};

// Iterative: Using Stack
// TC: O(n), where n is the number of nodes in the binary tree. Each node is visited exactly once.
// SC: O(h), where h is the height of the binary tree. This is the space required for the stack to store the nodes during traversal.

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(root == NULL)   //THIS IS IMP, SOMETIMES GIVES ERROR IF NOT WRITTEN SO BETTER  TO ALWAYS HANDLE THIS EDGE CASE 
        return {};
        vector<int> preorder;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty())
        {
            root = st.top();
            st.pop();
            preorder.push_back(root->val);
            if(root->right)   //RIGHT IS PUSHED BEFORE LEFT BCZ STACK IS LIFO AND PREORDER IS ROOT-LEFT-RIGHT SO WE NEED RIGHT AT LAST AND LEFT BEFORE IT
            st.push(root->right);
            if(root->left)    //NOT else if(), IT'S if FOR BOTH BCZ WE WANNA ADD BOTH CHILDREN IF EXISTS
            st.push(root->left);
        }
        return preorder;
    }
};
