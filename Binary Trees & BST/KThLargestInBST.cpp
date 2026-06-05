// Problem: Kth Largest in BST
// https://www.geeksforgeeks.org/problems/kth-largest-element-in-bst/1

// FOR BFS: https://takeuforward.org/data-structure/kth-largest-smallest-element-in-binary-search-tree


// Optimized approach: Inorder Traversal just first right subtree dfs, then current node processing, and then left. This is the reverse of what is done for kth smallest.
// TC:  O(N), where N is the number of nodes in the binary tree. The reason is that in the worst-case scenario, the inorder and reverse inorder traversals visit each node exactly once.
// SC: O(H), where H is the height of the binary tree.

class Solution {
    int Klargest;
    
  public:
    void inorder(Node* root, int& k) // THIS int& k IS VERY IMP
    //SINCE K SHOULD BE PASSSED BY REFERNECE OTHERWISE THE CHANGES IN K DONE DURING RECURSION WILL NOT BE REFLECTED
    // NO SYNTAX ERROR, BUT THE OUTPUT WILL BE WRONG
    {
        if(root == NULL)
        return;
        inorder(root->right, k);
        if(--k == 0)
        {
          Klargest = root->data;
          return;
        }
        inorder(root->left, k);
    }
  public:
    int kthLargest(Node *root, int k) {
        // Your code here
        if(root == NULL)
        return 0;
        inorder(root, k);
        return Klargest;
    }
};
