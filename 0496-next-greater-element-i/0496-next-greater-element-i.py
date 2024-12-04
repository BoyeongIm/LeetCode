class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        answer = []
        idx_dict = defaultdict(int)
        for i in range(len(nums2)):
            idx_dict[nums2[i]] = i
        for n in nums1:
            if idx_dict[n] == len(nums2)-1:
                answer.append(-1)
                continue
            idx = idx_dict[n]+1
            while n >= nums2[idx] and idx < len(nums2):
                if idx >= len(nums2)-1:
                    answer.append(-1)
                    break
                idx += 1
            if n < nums2[idx]:
                answer.append(nums2[idx])
        return answer
