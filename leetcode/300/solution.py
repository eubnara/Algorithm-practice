from typing import List


class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        res = []

        def binary_search(arr, val):
            length = len(arr)
            left = 0
            right = length - 1

            while left <= right:
                mid = (left + right) // 2
                if arr[mid] == val:
                    return mid
                elif arr[mid] > val:
                    right = mid - 1
                    continue
                else:
                    left = mid + 1
                    continue
            return left

        res.append(nums[0])
        for n in nums[1:]:
            if res[-1] < n:
                res.append(n)
                continue
            idx = binary_search(res, n)
            res[idx] = n
        return len(res)
