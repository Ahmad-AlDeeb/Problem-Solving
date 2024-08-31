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
void reverse(TreeNode* &node) {
    TreeNode* tmp = node->left;
    node->left = node->right;
    node->right = tmp;
}

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return nullptr;
        if(!root->left && !root->right) return root;
        
        reverse(root);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};
