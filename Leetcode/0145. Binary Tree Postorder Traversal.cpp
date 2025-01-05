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
        traverse(curNode->right);
        nodes.push_back(curNode->val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        traverse(root);
        return nodes;
    }
};
