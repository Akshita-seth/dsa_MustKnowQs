// Problem: Binary Tree DFS Traversal -> INORDER
// https://leetcode.com/problems/binary-tree-inorder-traversal/


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
    void inorder(TreeNode* root, vector<int>& arr)
    {
        if(root==nullptr)
        return;
        inorder(root->left,arr);
        arr.push_back(root->val);
        inorder(root->right,arr);
    }
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> arr;
        inorder(root,arr);
        return arr;
    }
};

// Iterative: Using Stack
// TC: O(n), where n is the number of nodes in the binary tree. Each node is visited exactly once.
// SC: O(h), where h is the height of the binary tree. This is the space required for the stack to store the nodes during traversal.

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        stack<TreeNode*> st;
        TreeNode* node = root;
        while(true) 
        {
            if(node)
            {
                st.push(node);
                node = node->left;
            }
            else
            {
                if(st.empty())
                break;
                node = st.top();
                st.pop();
                inorder.push_back(node->val);
                node = node->right;
            }
        }
        return inorder;
    }
};
