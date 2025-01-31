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
bool customSort(const pair<pair<int, int>, int>& lhs, const pair<pair<int, int>, int>& rhs) {
    if(lhs.first.second != rhs.first.second) {
        return lhs.first.second < rhs.first.second;
    }
    if(lhs.first.first != rhs.first.first) {
        return lhs.first.first < rhs.first.first;
    }
    return lhs.second < rhs.second;
}

class Solution {
    const int MAX_SIZE = 20;
    const int INVALID = -1;
    vector<pair<pair<int, int>, int>> nodes;

    void buildNodes(TreeNode* curNode, int row = 0, int col = 0) {
        if(!curNode) {
            return;
        }
        nodes.emplace_back(make_pair(row, col), curNode->val);
        buildNodes(curNode->left, row + 1, col - 1);
        buildNodes(curNode->right, row + 1, col + 1);
    }

    vector<vector<int>> getVerticalNodes() {
        sort(nodes.begin(), nodes.end(), customSort);
        vector<vector<int>> verticalNodes;
        int curCol = nodes.front().first.second;
        vector<int> colNodes;

        for(auto node : nodes) {
            if(node.first.second == curCol) {
                colNodes.push_back(node.second);
            }
            else {
                verticalNodes.push_back(colNodes);
                colNodes.clear();
                curCol = node.first.second;
                colNodes.push_back(node.second);
            }
        }
        verticalNodes.push_back(colNodes);

        return verticalNodes;
    }

public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        buildNodes(root);
        return getVerticalNodes();
    }
};
