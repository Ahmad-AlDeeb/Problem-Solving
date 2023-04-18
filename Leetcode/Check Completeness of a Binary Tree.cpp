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
 #include<queue>
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> nodes_queue;
        nodes_queue.push(root);
        bool no_more_allowed {false};

        while(!nodes_queue.empty()) {
            int size = nodes_queue.size();
            while(size--) {
                TreeNode* cur = nodes_queue.front();
                nodes_queue.pop();

                if(cur->left) {
                    if(no_more_allowed) return false;
                    nodes_queue.push(cur->left);
                } else no_more_allowed=true;
                if(cur->right) {
                    if(no_more_allowed) return false;
                    nodes_queue.push(cur->right);
                } else no_more_allowed=true;

            }
        }
        return true;
    }
};
