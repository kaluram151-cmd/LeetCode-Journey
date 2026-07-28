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
        if(root==NULL)
        {
            return { };
        }
        vector<vector<int>> ans;
        TreeNode* Node = root;
        queue<TreeNode*> st;
        st.push(Node);
        while(!st.empty())
        {
            int size = st.size();
            vector<int> level;
            for(int i = 0;i<size;i++)
            {
                TreeNode* x = st.front();
                st.pop();
                if(x->left!=NULL) st.push(x->left);
                if(x->right!=NULL) st.push(x->right);
                level.push_back(x->val);
            }
            ans.push_back(level);
        }
        return ans;
    }
};