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
    int targetSum;

    bool hasPath(TreeNode* curNode, int sum) {
        sum += curNode->val;

        if(!curNode->left && !curNode->right) {
            return sum == targetSum;
        }

        bool leftSubTreeResult  = (!curNode->left) ? false : hasPath(curNode->left, sum) ;
        bool rightSubTreeResult = (!curNode->right)? false : hasPath(curNode->right, sum);

        return leftSubTreeResult || rightSubTreeResult;
    }

public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        this->targetSum = targetSum;
        if(!root) {
            return false;
        }

        return hasPath(root, 0);
    }
};
