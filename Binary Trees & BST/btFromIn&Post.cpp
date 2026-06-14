// Problem: Construct binary tree from inorder and postorder
// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
// https://takeuforward.org/data-structure/construct-binary-tree-from-inorder-and-postorder-traversal

// TC: O(N), Every node is visited once.
// SC: O(N), Due to hashmap and recursion stack (up to tree height).


class Solution {
public:
    TreeNode* building(vector<int>& inorder, int inStart, int inEnd, vector<int>& postorder, int postStart, int postEnd, map<int,int>& inMap)
    {
        if(inStart > inEnd || postStart > postEnd)
        return NULL;
        TreeNode* root = new TreeNode(postorder[postEnd]);
        int inRootIdx = inMap[root->val];
        int leftSize = inRootIdx - inStart;
        root->left = building(inorder, inStart, inRootIdx-1, postorder, postStart, postStart+leftSize-1, inMap);
        root->right = building(inorder, inRootIdx+1, inEnd, postorder, postStart+leftSize, postEnd-1, inMap);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int> inMap;
        for(int i=0; i< inorder.size(); i++)
            inMap[inorder[i]] = i;
        return building(inorder,0, inorder.size()-1, postorder, 0, postorder.size()-1, inMap);
    }
};
