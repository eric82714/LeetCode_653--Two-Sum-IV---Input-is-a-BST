# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findTarget(self, root: TreeNode, k: int) -> bool:
        nums = []
        self.helper(root, nums)
        
        for i in range(len(nums)):
            for j in range(i+1, len(nums)):
                if nums[i] + nums[j] == k: return True
        
        return False
    
    def helper(self, root, nums):
        if not root: return
            
        nums.append(root.val)
            
        self.helper(root.left, nums)
        self.helper(root.right, nums)
