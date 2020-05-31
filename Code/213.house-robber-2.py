# 和198一样 分类讨论即可 抢0~n-1和1~n
# WA1: 0~n-1是[:-1] 不是 [:-2]
# 下面两次遍历使用了两种不同的动规 详见198

class Solution:
    def rob(self, nums: List[int]) -> int:
        if nums is None or len(nums) == 0:
            return 0
        if len(nums)<=3:
            return max(nums)
        
        # len num >= 4
        # if rob nums[0]
        a = nums[:-1] # remove last one 是-1不是-2
        x,y,z = a[0], max(a[0], a[1]), 0
        for i in range(2, len(a)):
            z = max(x+a[i], y)
            x,y,z = y,z,0
            # print("1",x,y,z)
        max_1 = max(x,y)

        a = nums[1:]
        a.insert(0,0)
        for i in range(3, len(a)):
            a[i] += max(a[i-2], a[i-3])
            # print(2,x,y,z)
        max_2 = max(a)

        return max(max_1, max_2)
