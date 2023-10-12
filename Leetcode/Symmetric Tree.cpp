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
    vector<int> left, right;
    bool isSymmetric(TreeNode* root) {
        if(root->left) traverse_l(root->left);
        else            left.push_back(-101);
        if(root->right) traverse_r(root->right);
        else            right.push_back(-101);

        return left == right;
    }

    void traverse_l(TreeNode* root) {
        left.push_back(root->val);

        if(root->left) traverse_l(root->left);
        else           left.push_back(-101);
        if(root->right) traverse_l(root->right);
        else            left.push_back(-101);
    }
    void traverse_r(TreeNode* root) {
        right.push_back(root->val);
        
        if(root->right) traverse_r(root->right);
        else            right.push_back(-101);
        if(root->left) traverse_r(root->left);
        else            right.push_back(-101);
    }
};
