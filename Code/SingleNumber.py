'''
   给定一个整数数组，除了某个元素外其余元素均出现两次。
   请找出这个只出现一次的元素。
'''

class Solution:
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        a = 0
        for num in nums:
            a ^= num
        return a