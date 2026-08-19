// Problem: Serialize and Deserialize Binary Tree
// https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/

// 1. stringstream and getline
// stringstream stream_name(string name)

// Reads a line from an input stream into a string
// std::getline(stream, stringVariable);

// Reads until a specific delimiter (instead of newline)
// std::getline(stream, stringVariable, delimiterChar);

// 2. string s = to_string(numeric data/variable)
// 3. int num = stoi("25")
// 4. string_name.sppend(string); no need of "" inside the append ()

// You only push children if they’re non-null. Its' a mistake!
// For proper serialization, you need to push both left and right children even if they’re null. Otherwise, you lose structure information.


// TC: O(N)
// serialize function: O(N), where N is the number of nodes in the tree. This is because the function performs a level-order traversal of the tree, visiting each node once.
// deserialize function: O(N), where N is the number of nodes in the tree. Similar to the serialize function, it processes each node once while reconstructing the tree.

// SC: O(N)
// serialize function: O(N), where N is the maximum number of nodes at any level in the tree. In the worst case, the queue can hold all nodes at the last level of the tree.
// deserialize function: O(N), where N is the maximum number of nodes at any level in the tree. The queue is used to store nodes during the reconstruction process, and in the worst case, it may hold all nodes at the last level.


class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ser = "";
        if(!root)
        return ser;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();
            if(node == NULL)
            ser.append("nullptr,");
            else{
            ser.append(to_string(node->val));
            ser.append(",");
            }
                if(node != NULL)  //here only node is checked as NULL and not node's left and right bcz i want to insert in the queue if it's null bcz if its null i am appending it as #
                { 
                    q.push(node->left);
                    q.push(node->right);
                }
            }
        return ser;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0)
        return NULL;
        stringstream s(data); //it allows the string to be iterated over as objects
        string str;
        getline(s, str, ',');
        TreeNode* root = new TreeNode(stoi(str)); 
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();
            
            getline(s,str,',');
            if(str == "nullptr")
            node->left = NULL;
            else{
                TreeNode* leftNode = new TreeNode(stoi(str));
                node->left = leftNode;
                q.push(leftNode);
            }

            getline(s,str,',');
            if(str == "nullptr")
            node->right = NULL;
            else{
                TreeNode* rightNode = new TreeNode(stoi(str));
                node->right = rightNode;
                q.push(rightNode);
            }
        }
        return root;
    }
};


// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));



// alternate for Serialize

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ser = "";
        if (!root)
            return ser;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (node == NULL)
                    ser += "nullptr,";
                else {
                    ser += to_string(node->val) + ",";
                    q.push(node->left);
                    q.push(node->right);
                }
            }
        }
        return ser;
    }
