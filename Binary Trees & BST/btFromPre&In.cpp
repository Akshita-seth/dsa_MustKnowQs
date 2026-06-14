// Problem: Construct a Binary Tree from Inorder and Preorder
// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/ 
// https://www.youtube.com/watch?v=aZNaLrVebKQ


// TC: O(N), as each node is visited once.
// SC: O(N), for the hashmap and recursion stack (worst case when tree is skewed).


class Solution {
    //map<int,int> mpp;  //keep map either global or pass in the function definition like below
public:
    TreeNode* building(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, map<int,int>& mpp)
    {
        if(preStart > preEnd || inStart > inEnd)
        return NULL;
        TreeNode* root = new TreeNode(preorder[preStart]);
        int inRootIdx = mpp[root->val];
        int leftSize = inRootIdx - inStart;
        root->left = building(preorder, preStart+1, preStart+leftSize, inorder, inStart, inRootIdx-1, mpp);
        root->right = building(preorder, preStart+leftSize+1, preEnd, inorder, inRootIdx+1, inEnd, mpp);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        map<int,int> mpp;
        for(int i=0; i<inorder.size(); i++)
            mpp[inorder[i]] = i;

        return building(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, mpp);
    }
};
