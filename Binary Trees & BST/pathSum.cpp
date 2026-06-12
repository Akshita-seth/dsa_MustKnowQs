// Problems: Path SUM [Root-To-Leaf]
// The helper function pattern is only needed when you want to track extra state (like a vector of nodes for Path Sum II, or prefix sums for Path Sum III).
// For Path Sum I, recursion in the same function is clean and sufficient.

// PathS Sum I
// https://leetcode.com/problems/path-sum/

// BFS: For Path Sum I, a brute force approach would mean:
// Enumerating all root-to-leaf paths in the tree. For each path, compute the sum of its nodes.Check if any equals the target.
// This can be done by: Doing a DFS that collects every path into a vector, then summing at the end.


bool hasPathSum(TreeNode* root, int targetSum) {
    if (!root) return false;
    vector<vector<int>> allPaths;
    vector<int> current;
    
    // DFS to collect every root-to-leaf path
    function<void(TreeNode*)> dfs = [&](TreeNode* node) {
        if (!node) return;
        current.push_back(node->val);
        if (!node->left && !node->right) {
            allPaths.push_back(current);
        } else {
            dfs(node->left);
            dfs(node->right);
        }
        current.pop_back();
    };
    
    dfs(root);
    
    // Check sums of all collected paths
    for (auto &path : allPaths) {
        int sum = 0;
        for (int val : path) sum += val;
        if (sum == targetSum) return true;
    }
    return false;
}

//So instead of writing a separate helper function, the brute force code I showed defines a local recursive function inline. 
//It’s just a stylistic choice — you can absolutely write it as a normal helper function if you prefer.

void dfs(TreeNode* node, vector<int>& current, vector<vector<int>>& allPaths) {
    if (!node) return;
    current.push_back(node->val);
    if (!node->left && !node->right) {
        allPaths.push_back(current);
    } else {
        dfs(node->left, current, allPaths);
        dfs(node->right, current, allPaths);
    }
    current.pop_back();
}

bool hasPathSum(TreeNode* root, int targetSum) {
    if (!root) return false;
    vector<vector<int>> allPaths;
    vector<int> current;
    dfs(root, current, allPaths);

    for (auto &path : allPaths) {
        int sum = 0;
        for (int val : path) sum += val;
        if (sum == targetSum) return true;
    }
    return false;
}



//Optimized: Instead of storing paths, subtract node values as you go down; at a leaf, check if the remaining sum is zero.
// TC: O(N), since each node is visited once.
// SC: O(H) where H is the height of the tree (stack depth). Worst case O(N) for a skewed tree, best case O(logN) for a balanced tree.

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL)
        return false;
        if(!root->left && !root->right)
        return targetSum == root->val; //Basically checking if the leaf node's value is equal to the remaining targetSum i.e. will it be in the path
        return hasPathSum(root->left, targetSum-root->val) || hasPathSum(root->right, targetSum-root->val);

    }
};


// PATH SUM II
// https://leetcode.com/problems/path-sum-ii/description/


//BFS:
// Brute force would mean:
// Generate all root-to-leaf paths (store them in a list).
// For each path, compute the sum separately. Check if any equals the target.
// This wastes effort because you compute sums after building paths, instead of checking during traversal.
// The brute force version is mainly useful for understanding, but not for efficiency.
// TC: O(N.H) (same asymptotic, but less efficient in practice).
// SC: O(N.H) (storing all paths explicitly).


// Optimized: DFS + backtracking solution.
// TC: Each node is visited once → O(N) At each leaf, you may copy the current path into paths. Copying costs up to O(H) H is the height of the tree.
// If there are many leaves, this adds up to O(N.H) in the worst case.
// Final: Worst case: O(N.H) 
// Average case: closer to O(N) if the number of leaves is small.

//SC: 
// Recursion stack: O(H)
// Temporary path (temp): O(H)
// Result storage (paths): In the worst case, if all root-to-leaf paths are valid, you store them all → O(N.H)

class Solution {
public:
    void findPaths(TreeNode* root, int targetSum, vector<int>& temp, vector<vector<int>>& paths)
    {
        if(!root)
        return;
        temp.push_back(root->val);
        if(!root->left && !root->right)
        {
            if(targetSum == root->val)
                paths.push_back(temp);
        }
        findPaths(root->left, targetSum - root->val, temp, paths);
        findPaths(root->right, targetSum - root->val, temp, paths);
        temp.pop_back();  //ensures backtracking
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> paths;
        vector<int> temp;
        if(!root)
        return paths;
        findPaths(root, targetSum, temp, paths);
        return paths;
    }
};


// PATH SUM III
// https://leetcode.com/problems/path-sum-iii/description/






