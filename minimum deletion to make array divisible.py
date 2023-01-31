class Solution:
    def minOperations(self, nums: List[int], numsDivide: List[int]) -> int:
        nums.sort()
        g= numsDivide[0]
        for x in numsDivide[1:]:
            g=gcd(g,x)
        for i,x in enumerate(nums):
            if g % x ==0:
                return i

        return -1