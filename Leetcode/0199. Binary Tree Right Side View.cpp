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
    const int INVALID = -101;
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> rightSideNodes;
        if(!root) {
            return rightSideNodes;
        }

        queue<TreeNode*> nodes;
        nodes.push(root);
        while(!nodes.empty())         {
            int levelSize = nodes.size();
            int mostRightNodeVal {INVALID};
            
            while(levelSize--) {
                TreeNode* currentNode = nodes.front();
                nodes.pop();
                mostRightNodeVal = currentNode->val;

                if(currentNode->left) {
                    nodes.push(currentNode->left);
                }
                if(currentNode->right) {
                    nodes.push(currentNode->right);
                }
            }

            if(mostRightNodeVal != INVALID) {
                rightSideNodes.push_back(mostRightNodeVal);
            }
        }

        return rightSideNodes;
    }
};
