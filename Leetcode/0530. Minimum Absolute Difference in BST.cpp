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
    int lastVal {-1};
    int minDiff {100000};

    void inOrderTraverse(TreeNode* curNode) {
        if(!curNode) {
            return ;
        }
        int curVal = curNode->val;

        inOrderTraverse(curNode->left);
        if(lastVal == -1) {
            lastVal = curVal;
        }
        else {
            minDiff = min(minDiff, curVal - lastVal);
            lastVal = curVal;
        }
        inOrderTraverse(curNode->right);
    }

public:
    int getMinimumDifference(TreeNode* root) {
        inOrderTraverse(root);
        return minDiff;
    }
};
