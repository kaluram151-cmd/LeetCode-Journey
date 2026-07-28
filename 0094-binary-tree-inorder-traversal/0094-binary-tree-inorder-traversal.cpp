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
    vector<int> inorderTraversal(TreeNode* root) {
        if(root==NULL)
        {
            return { };
        }
        stack<TreeNode*> st;
        vector<int> inorder;
        TreeNode* Node = root;
        while(true)
        {
            if(Node!=NULL)
            {
                st.push(Node);
                Node = Node->left;
            }
            else
            {
                if(st.empty()) break;
                Node = st.top();
                inorder.push_back(st.top()->val);
                st.pop();
                Node = Node->right;
            }
        }
        return inorder;
    }
};