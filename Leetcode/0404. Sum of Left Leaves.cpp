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
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root) {
            return 0;
        }
        
        int leftSubTreeSum;
        if(root->left && !root->left->left && !root->left->right) {
            leftSubTreeSum = root->left->val;
        }
        else  {
            leftSubTreeSum = sumOfLeftLeaves(root->left);
        }

        int rightSubTreeSum = sumOfLeftLeaves(root->right);
        
        return leftSubTreeSum + rightSubTreeSum;
    }
};
