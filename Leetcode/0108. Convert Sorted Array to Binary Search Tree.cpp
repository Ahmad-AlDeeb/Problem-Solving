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
    void insert(TreeNode *current, int num) {
        while(true) {
            if(num < current->val) {
                if(!current->left) {
                    current->left = new TreeNode(num);
                    return;
                }
                    
                current = current->left;
            }
            else {
                if(!current->right) {
                    current->right = new TreeNode(num);
                    return;
                }
                
                current = current->right;
            }
                
        }
        
    }

    void fill(vector<int>& nums, TreeNode *root, int left, int right) {
        if(left > right)
            return;
        
        int mid = left + (right-left) / 2;
        insert(root, nums[mid]);

        fill(nums, root, left, mid-1);
        fill(nums, root, mid+1, right);
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int mid = nums.size() / 2;
        TreeNode* tree = new TreeNode(nums[mid]);

        fill(nums, tree, 0, mid-1);
        fill(nums, tree, mid+1, nums.size()-1);

        return tree;
    }
};
