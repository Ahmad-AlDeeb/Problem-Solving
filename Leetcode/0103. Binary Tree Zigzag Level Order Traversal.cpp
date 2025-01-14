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
    void handleRight(TreeNode* curNode, vector<TreeNode*>& nextLevelNodes) {
        if(curNode->right) {
            nextLevelNodes.push_back(curNode->right);
        } 
    }
    void handleLeft(TreeNode* curNode, vector<TreeNode*>& nextLevelNodes) {
        if(curNode->left) {
            nextLevelNodes.push_back(curNode->left);
        } 
    }


public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> zigzagNodes;
        if(!root) {
            return zigzagNodes;
        }
        zigzagNodes.push_back({root->val});
        
        queue<TreeNode*> curLevelNodes({root});
        bool isLeftToRight {true};
        
        while(!curLevelNodes.empty()) {
            int size = curLevelNodes.size();
            vector<TreeNode*> nextLevelNodes;

            isLeftToRight = !isLeftToRight;
            while(size--) {
                TreeNode* curNode = curLevelNodes.front();
                curLevelNodes.pop();

                if(isLeftToRight) {
                    handleRight(curNode, nextLevelNodes);
                    handleLeft(curNode, nextLevelNodes);
                }
                else {
                    handleLeft(curNode, nextLevelNodes);
                    handleRight(curNode, nextLevelNodes);
                }
            }
            
            if(!nextLevelNodes.empty()) {
                vector<int> nextLevelVal;
                
                reverse(nextLevelNodes.begin(), nextLevelNodes.end());
                for(auto node : nextLevelNodes) {
                    nextLevelVal.push_back(node->val);
                    curLevelNodes.push(node);
                }
                
                zigzagNodes.push_back(nextLevelVal);
            }
        }
        
        return zigzagNodes;
    }
};
