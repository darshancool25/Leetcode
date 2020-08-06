# https://leetcode.com/problems/single-number/

class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        temp = 0;
        for item in nums:
            temp = temp^item
        return temp