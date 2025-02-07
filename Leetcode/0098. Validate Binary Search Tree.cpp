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
    bool isValidBST(TreeNode* curNode, long long leftBound, long long rightBound) {
        if(!curNode) {
            return true;
        }

        int curVal = curNode->val;

        if(curVal <= leftBound || curVal >= rightBound) {
            return false;
        }

        return isValidBST(curNode->left, leftBound, curVal) && isValidBST(curNode->right, curVal, rightBound);
    }


public:
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, LLONG_MIN, LLONG_MAX);
    }
};
