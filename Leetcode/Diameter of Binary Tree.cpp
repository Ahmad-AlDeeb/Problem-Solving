#include <bits/stdc++.h>
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
    int diameterOfBinaryTree(TreeNode* root) {
        pair<int,int> answer = ans(root);
        return answer.first;
    }


    pair<int,int> ans(TreeNode* root) {
        pair<int, int> res;
        pair<int, int> l_diameter;
        pair<int, int> r_diameter;

        if(!root->left and !root->right) return res;
        if(root->left) {
            l_diameter = ans(root->left);
            res.first += (1 + l_diameter.second);
        }
        if(root->right) {
            r_diameter = ans(root->right);
            res.first += (1 + r_diameter.second);
        }


        res.first = max({res.first, l_diameter.first, r_diameter.first});
        res.second = 1 + max(l_diameter.second, r_diameter.second);
        return res;
    }
};
