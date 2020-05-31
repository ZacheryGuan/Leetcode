# dp的两种方式 
# 1. 构建dp数组 看dp[i]最多能抢多少
# 2. 在n[i]必须要抢的情况下 最多能抢到多少
# 选择的方式是 看哪个方法的转移状态方程更好写
# credit to wangzhibo @ May 31st, 2020

# 第一种dp
class Solution:
    def rob(self, nums: List[int]) -> int:
        if nums is None || len(nums) == 0:  # 注意空输入或Nonw
            return 0

        if len(nums) <= 2:
            return max(nums[:])
        
        money = [0]*len(nums)
        money[0], money[1] = nums[0], max(nums[0:2])
        i = 2
        while i < len(nums): 
            money[i] = (max(money[i-1], money[i-2]+nums[i]))
            # print(money)
            i += 1
        
        return max(money)

# 第二种dp
class RefSolution:
    def rob(self, nums: List[int]) -> int:
        nums.insert(0,0)
        for i in range(3, len(nums)):
            nums[i] += max(nums[i-2], nums[i-3])
        return max(nums)