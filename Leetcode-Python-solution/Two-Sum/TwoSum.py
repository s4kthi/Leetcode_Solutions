class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        m = {}
        for i, num in enumerate(nums):
            x = target - num
            if x in m:
                return [m[x], i]
            else:
                m[num] = i
        return [-1, -1]