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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> levelOrderNodes;
        if(!root) {
            return levelOrderNodes;
        }

        queue<TreeNode*> nodes;
        nodes.push(root);

        while(!nodes.empty()) {
            int levelSize = nodes.size();
            vector<int> currentLevelNodes;

            while(levelSize--) {
                TreeNode* currentNode = nodes.front();
                nodes.pop();
                currentLevelNodes.push_back(currentNode->val);

                if(currentNode->left) {
                    nodes.push(currentNode->left);
                }
                if(currentNode->right) {
                    nodes.push(currentNode->right);
                }
            }

            if(!currentLevelNodes.empty()) {
                levelOrderNodes.push_back(currentLevelNodes);
            }
        }

        return levelOrderNodes;
    }
};
