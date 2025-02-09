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
    TreeNode* target1 = nullptr;
    TreeNode* target2 = nullptr;
    TreeNode* lastNode = nullptr;
    long lastVal = INT_MIN - 1L;
    
    void findTargets(TreeNode* curNode) {
        if(!curNode) {
            return;
        }

        findTargets(curNode->left);

        if(curNode->val < lastVal) {
            if(!target1) {
                target1 = lastNode;
                target2 = curNode;
            }
            else {
                target2 = curNode;
            }
        }

        lastNode = curNode;
        lastVal = lastNode->val;
        
        findTargets(curNode->right);
    }

public:
    void recoverTree(TreeNode* root) {
        findTargets(root);
        swap(target1->val, target2->val);
    }
};
