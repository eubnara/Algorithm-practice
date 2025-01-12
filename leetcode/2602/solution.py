from typing import List
import bisect


class Solution:
    def minOperations(self, nums: List[int], queries: List[int]) -> List[int]:
        self.cache = {}
        nums.sort()
        length = len(nums)
        answer = []
        accum = [0]
        for i in range(length):
            accum.append(accum[i] + nums[i])
        for q in queries:
            if q in self.cache:
                answer.append(self.cache[q])
                continue
            i = bisect.bisect_left(nums, q)
            ans = (q * i - accum[i]) + (accum[-1] - accum[i] - q * (length - i))
            answer.append(ans)
            self.cache[q] = ans
        return answer


print(Solution().minOperations([3, 1, 6, 8], [1, 5]))
