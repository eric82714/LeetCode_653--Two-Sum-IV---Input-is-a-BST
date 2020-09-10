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
    void helper(TreeNode* root, int* nums, int* index) {
        if(!root) return;
        
        nums[10000-*index] = root->val;
        *index = *index - 1;
            
        helper(root->left, nums, index);
        helper(root->right, nums, index);
    }
    
    bool findTarget(TreeNode* root, int k) {
        int size = 10000;
        int len = size;
        int* nums = new int[size]{0};
        helper(root, nums, &size);
        
        for(int i = 0; i < len-size; i++) {
            cout << nums[i];
            for(int j = i+1; j < len-size; j++)
                if(nums[i] + nums[j] == k) return true;
        }
        
        delete [] nums;
        return false;
    }
};
