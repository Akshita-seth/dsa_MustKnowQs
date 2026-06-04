// Problem: Binary Tree DFS Traversal -> POSTORDER
// https://leetcode.com/problems/binary-tree-inorder-traversal/


// Recursive:
// TC: O(N) [N=No. of nodes] bcz each node is visited once
// SC: O(Height of Tree) due to recursion stack. 
// In the worst case (skewed tree), height = N → SC = O(N).
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
    void postorder(TreeNode* root, vector<int>& arr)
    {
        if(root==nullptr)
        return;
        postorder(root->left,arr);
        postorder(root->right,arr);
        arr.push_back(root->val);
    }
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> arr;
        postorder(root,arr);
        return arr;
    }
};

// Iterative: Using 2 Stack => Stack 1 to traverse the BT and Stack 2 to store the reverse of Post-Order 
// TC: O(n), where n is the number of nodes in the binary tree. Each node is visited exactly once.
// SC = O(N) always, since stacks can grow to hold all nodes. [yes 2N bcz of 2 stacks but ignore constant 2]

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(root == NULL)
        return {};
        // 2 STACKS
        vector<int> postorder;
        stack<TreeNode*> st1, st2;
        st1.push(root);
        while(!st1.empty())
        {
            root = st1.top();
            st1.pop();
            st2.push(root);
            if(root->left)
            st1.push(root->left);
            if(root->right)
            st1.push(root->right);
        }
        while(!st2.empty())
        {
            postorder.push_back(st2.top()->val);
            st2.pop();
        }
        return postorder;
    }
};


// Iterative: Using 1 Stack
// TC: O(2*N), FIRST THE TREE IS TRAVERSED AN NODES ARE PUSHED INTO THE STACK, WHILE COMING BACK, EACH NODE IS CHECKED AND PUSHED. HENCE VISITED TWICE.
// SC: O(N)

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(root == NULL)
            return {};
        vector<int> postorder;
        stack<TreeNode*> st;
        TreeNode* curr = root;
        TreeNode* temp = nullptr;

        while(curr != NULL || !st.empty())
        {
            if(curr)  // push left children
            {
                st.push(curr);
                curr = curr->left;
            }
            else
            {
                temp = st.top()->right;  // check right child
                if(temp)  
                    curr = temp;  // move to right subtree
                else  
                {
                    // process node with no right child
                    temp = st.top();
                    st.pop();
                    postorder.push_back(temp->val);

                    // backtrack: process ancestors whose right is done
                    while(!st.empty() && temp == st.top()->right)
                    {
                        temp = st.top();
                        st.pop();
                        postorder.push_back(temp->val);
                    }
                }   
            }
        }
        return postorder;
    }
};
