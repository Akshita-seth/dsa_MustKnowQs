// Flatten Binary tree to Linked List
// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/
// https://www.youtube.com/watch?v=sWf7k1x9XR4

// Recursive Soln: Reversed Preorder DFS, i.e., Right-Left-Root
// TC: O(N), SC: O(H)
// In worst case (skewed tree), recursion depth = O(N)
// In average case (balanced tree), depth = O(logN)



class Solution {
    TreeNode* prev = nullptr;  //global pointer prev
public:
    void flatten(TreeNode* root) {
        if(!root)
        return;
        
        flatten(root->right);
        flatten(root->left);

        root->right = prev;
        root->left = NULL;
        prev = root;
    }
};


// Iterative SOln: Using stack (Just to know, no need to tell in interview
// TC: O(N), SC: O(N)

class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root)
        return;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty())
        {
            TreeNode* curr = st.top();
            st.pop();
            if(curr->right)
            st.push(curr->right); // inserting right before left 
            if(curr->left)
            st.push(curr->left);
            if(!st.empty())
            curr->right = st.top();
            curr->left = NULL;
        }
    }
};


// Optimized: Morris Traversal Style
// Intuition: On the left subtree of the root(curr), go to the last node of the preorder and connect it to the right subtree of the root(curr).
// TC: O(N), SC: O(1)

class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root)
        return;
        TreeNode* curr = root;
        while(curr != NULL)
        {
            if(curr->left != NULL)
            {
                TreeNode* prev = curr->left;
                while(prev->right)
                  prev = prev->right;
                
                prev->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }
            curr = curr->right;
        }
    }
};



