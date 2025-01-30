class Solution:

    def numSquares(self, n: int) -> int:

        dp = [10000] * (n + 1)
        dp[0] = 0
        for i in range(1, n + 1):
            j = 1
            min_val = 10000
            while j * j <= i:
                if dp[i - j * j] + 1 < min_val:
                    min_val = dp[i - j * j] + 1
                j += 1
            dp[i] = min_val
        return dp[n]


s = Solution()
print(s.numSquares(12))
print(s.numSquares(14))
