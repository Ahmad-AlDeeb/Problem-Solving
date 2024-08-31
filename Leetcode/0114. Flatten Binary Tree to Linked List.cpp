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

    vector<TreeNode*> v;

    void rec(TreeNode* root) {
        if(!root) return;

        v.push_back(root);
        rec(root->left);
        rec(root->right);
    }
    
    void flatten(TreeNode* root) {
        if(!root) return;
        rec(root);


        for(int i{}; i<v.size()-1; i++) {
            v[i]->right = v[i+1];
            v[i]->left = nullptr;
        }
        v.back()->right = v.back()->left = nullptr;
    }
};
