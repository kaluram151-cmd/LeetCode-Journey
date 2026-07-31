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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL) return { };
        vector<vector<int>> ans;
        queue<TreeNode*> qu;
        qu.push(root);
        int flag = 0;
        while(!qu.empty())
        {
            int size = qu.size();
            vector<int> level;
            for(int i = 0;i<size;i++)
            {
                TreeNode* x = qu.front();
                qu.pop();
                if(x->left!=NULL) qu.push(x->left);
                if(x->right!=NULL) qu.push(x->right);
                level.push_back(x->val);
            }
            if(flag%2==1)
            {
                reverse(level.begin(),level.end());
            }
            flag++;
            ans.push_back(level);
        }
        return ans;
    }
};