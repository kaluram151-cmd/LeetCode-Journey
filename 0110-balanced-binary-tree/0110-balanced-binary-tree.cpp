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
private:
    int length(TreeNode* root)
    {
        if(root==NULL)
        {
            return 0;
        }
        int lh = length(root->left);
        int rh = length(root->right);
        return 1+max(lh,rh);
    }
public:
    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;
        int lh = length(root->left);
        int rh = length(root->right);
        if(abs(rh-lh)>1)
        {
            return false;
        }
        bool b1 = isBalanced(root->left);
        bool b2 = isBalanced(root->right);
        if(b1==false||b2==false)
        {
            return false;
        }
        return true;
    }
};