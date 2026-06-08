// Problem: Binary Tree Right Side View
// 



class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> rightV;
        if(!root)
        return rightV;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int size= q.size();
            vector<int> temp;
            for(int i=0;i<size;i++)
            {
                TreeNode* node= q.front();
                q.pop();
                temp.push_back(node->val);
                if(node->left)
                q.push(node->left);
                if(node->right)
                q.push(node->right);
            }
            rightV.push_back(temp.back());
        }
        return rightV;
    }
};
