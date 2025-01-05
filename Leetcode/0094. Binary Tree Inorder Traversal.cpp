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
    vector<int> nodes;
    void traverse(TreeNode* curNode) {
        if(!curNode) {
            return;
        }
        traverse(curNode->left);
        nodes.push_back(curNode->val);
        traverse(curNode->right);
    }
    
public:
    vector<int> inorderTraversal(TreeNode* root) {
        traverse(root);
        return nodes;
    }
};
