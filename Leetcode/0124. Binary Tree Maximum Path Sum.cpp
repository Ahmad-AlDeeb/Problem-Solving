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
    int calcMaxSum(TreeNode* curNode, int& maxSum) {
        if(!curNode) {
            return 0;
        }

        int maxLeftSum = max(0, calcMaxSum(curNode->left, maxSum));
        int maxRightSum = max(0, calcMaxSum(curNode->right, maxSum));
        
        int newSum = curNode->val + maxLeftSum + maxRightSum;
        maxSum = max(maxSum, newSum);

        return curNode->val + max(maxLeftSum, maxRightSum);
    }

public:
    int maxPathSum(TreeNode* root) {
        int maxSum {INT_MIN};
        calcMaxSum(root, maxSum);
        return maxSum;
    }
};
