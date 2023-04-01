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
    bool solve(TreeNode* curr1 , TreeNode* curr2) {
        if(!curr1 && !curr2)
            return true;
        if((curr1 && !curr2) || (!curr1 && curr2) || (curr1->val != curr2->val))
            return false;
        return solve(curr1->right , curr2->left) && solve(curr1->left , curr2->right);
    }
    bool isSymmetric(TreeNode* root) {
        return solve(root->left , root->right);
    }
};