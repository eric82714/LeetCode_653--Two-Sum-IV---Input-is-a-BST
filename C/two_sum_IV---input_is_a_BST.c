/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void helper(struct TreeNode* root, int* nums, int* index){
    if(!root) return;
        
    nums[10000-*index] = root->val;
    *index = *index - 1;
            
    helper(root->left, nums, index);
    helper(root->right, nums, index);
}

bool findTarget(struct TreeNode* root, int k){
    int size = 10000;
    int len = size;
    int* nums = calloc(size, sizeof(int));
    helper(root, nums, &size);
        
    for(int i = 0; i < len-size; i++){
        for(int j = i+1; j < len-size; j++)
            if(nums[i] + nums[j] == k) return true;
    }
        
    free(nums);
    return false;
}
