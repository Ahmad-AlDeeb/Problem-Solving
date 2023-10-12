#include<bits/stdc++.h>
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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if(!root1 and !root2) return true;
				if(!root1 or !root2) return false;

				return parenthesize_canonical(root1) == parenthesize_canonical(root2);
    }

    string parenthesize_canonical(TreeNode* root) {
		string repr = "(" + to_string(root->val);

		vector<string> v;

		if (root->left) v.push_back(parenthesize_canonical(root->left));
		else v.push_back("()");

		if (root->right) v.push_back(parenthesize_canonical(root->right));
		else v.push_back("()");
			

		sort(v.begin(), v.end());
		for (int i = 0; i < (int)v.size(); ++i)
			repr += v[i];

		repr += ")";
		return repr;
	}
};
