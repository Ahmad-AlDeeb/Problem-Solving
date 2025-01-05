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
    int counter{};
    int k;
    int answer;

    void traverse(TreeNode* node) {
        if(!node) return;
        traverse(node->left);
        counter++;
        if(counter == k) {
            answer = node->val;
        }
        traverse(node->right);
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        this->k = k;
        traverse(root);
        return answer;
    }
};
