/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    TreeNode* LCA = nullptr;
    int pVal;
    int qVal;

    bool isFound(TreeNode* curNode) {
        if(!curNode) {
            return false;
        }
        bool leftResult  = isFound(curNode->left);
        bool rightResult = isFound(curNode->right);

        if(curNode->val == pVal || curNode->val == qVal) {
            if(leftResult || rightResult) {
                LCA = curNode;
            }
            return true;
        }

        if(leftResult && rightResult) {
            LCA = curNode;
        }

        return leftResult || rightResult;
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        pVal = p->val;
        qVal = q->val;

        isFound(root);
        return LCA;
    }
};
