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
    void solve(TreeNode* root , string curr , int& ans) {
        if(!root->left && !root->right) {
            ans += stoi(curr + to_string(root->val));
            return;
        }
        if(root->left)
            solve(root->left , curr + to_string(root->val) , ans);
        if(root->right)
            solve(root->right ,curr + to_string(root->val) , ans);
    }
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        solve(root , "" , ans);
        return ans;
    }
};