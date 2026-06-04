// Problem: Pre and Post Traversals all in one Traversal
// https://www.geeksforgeeks.org/dsa/pre-order-post-order-and-in-order-traversal-of-a-binary-tree-in-one-traversal-using-recursion/

// Iterative: Using 1 stack. Taking 3 states as pre, in and post.
// TC: O(N), SC: O(N)


// Solution class containing the traversal function
class Solution {
public:
    // Function to get the Preorder,
    // Inorder and Postorder traversal
    // Of Binary Tree in One traversal
    vector<vector<int>> preInPostTraversal(Node* root) {
        // Vectors to store traversals
        vector<int> pre, in, post;

        // If the tree is empty,
        // return empty traversals
        if (root == NULL) {
            return {};
        }

        // Stack to maintain nodes
        // and their traversal state
        stack<pair<Node*, int>> st;

        // Start with the root node
        // and state 1 (preorder)
        st.push({root, 1});

        while (!st.empty()) {
            auto it = st.top();
            st.pop();

            // this is part of pre
            if (it.second == 1) {
                // Store the node's data
                // in the preorder traversal
                pre.push_back(it.first->data);
                // Move to state 2
                // (inorder) for this node
                it.second = 2;
                // Push the updated state
                // back onto the stack
                st.push(it); 

                // Push left child onto
                // the stack for processing
                if (it.first->left != NULL) {
                    st.push({it.first->left, 1});
                }
            }

            // this is a part of in
            else if (it.second == 2) {
                // Store the node's data
                // in the inorder traversal
                in.push_back(it.first->data);
                // Move to state 3
                // (postorder) for this node
                it.second = 3;
                // Push the updated state
                // back onto the stack
                st.push(it); 

                // Push right child onto
                // the stack for processing
                if (it.first->right != NULL) {
                    st.push({it.first->right, 1});
                }
            }

            // this is part of post
            else {
                // Store the node's data
                // in the postorder traversal
                post.push_back(it.first->data);
            }
        }

        // Returning the traversals
        vector<vector<int>> result;
        result.push_back(pre);
        result.push_back(in);
        result.push_back(post);
        return result;
    }
};

// RECURSIVE: 


// preorder postorder and inorder method
void PostPreInOrderInOneFlowRecursive(Node* root, vector<int>& pre, vector<int>& post, vector<int>& in)
{
    if (root == NULL)
        return;
    // Pushes the root data into the pre order vector
    pre.push_back(root->data);
    // Recursively calls for the left node
    PostPreInOrderInOneFlowRecursive(
        root->left, pre, post, in);
    // Pushes node data into the inorder vector
    in.push_back(root->data);
    // Recursively calls for the right node
    PostPreInOrderInOneFlowRecursive(
        root->right, pre, post, in);
    // Pushes the node data into the Post Order
    // Vector
    post.push_back(root->data);
}

