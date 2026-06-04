// Problem: Lever Order Traversal
// https://leetcode.com/problems/binary-tree-level-order-traversal/description/

// Approach: Using a QUEUE
// TC: O(N) Each node is visited once during the level-order traversal.
// SC: O(N) The space is used by the queue to store nodes at each level, and in the worst case, it can hold all nodes at the last level.


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
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL)
        return {};
        vector<vector<int>> bfs;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            vector<int> temp;
            int size = q.size(); //IMP: CALC SIZE BEFORE FOR LOOP BCZ WRITING q.size() INSIDE LOOP CONDITION AREA WOULD BE WRONG SINCE THE QUEUE GETS MODIFIED DURING THE ITERATIONS 
            for(int i=0; i<size; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                temp.push_back(node->val);
                if(node->left)
                q.push(node->left);
                if(node->right)
                q.push(node->right);
            }
            bfs.push_back(temp);
        }
        return bfs;
    }
};
