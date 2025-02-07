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
    int goodNodesCount{};

    void traverse(TreeNode* curNode, int maxValue) {
        if(!curNode) {
            return;
        }

        if(curNode->val >= maxValue) {
            maxValue = curNode->val;
            goodNodesCount++;
        }

        traverse(curNode->left,  maxValue);
        traverse(curNode->right, maxValue);
    }

public:
    int goodNodes(TreeNode* root) {
        traverse(root, root->val);
        return goodNodesCount;
    }
};
