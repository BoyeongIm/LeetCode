class Solution(object):
    def largestNumber(self, nums):
        nums = [str(num) for num in nums]
        nums_sorted = sorted(nums, key=lambda x: x * 10, reverse=True)
        print(nums_sorted)
        ans = ""
        for n in nums_sorted:
            ans += n
        if ans[0] == "0":
            return "0"
        return ans
