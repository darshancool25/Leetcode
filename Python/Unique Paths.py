# https://leetcode.com/problems/unique-paths/

class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        N = m-1 + n-1
        numr,denr = 1,1
        for i in range(m-1):
            numr *= N-i
        for i in range(1,m):
            denr *= i
        return numr//denr
    
# Using inbuilt function for calculating nCr
class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        return comb(n+m-2 , m-1)
