# https://leetcode.com/problems/find-all-duplicates-in-an-array/

class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        ans = []
        for item in nums:
            item = abs(item)
            nums[item-1] *= -1
            if(nums[item-1]>0):
                ans.append(item)
        return ans