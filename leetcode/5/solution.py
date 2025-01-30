class Solution:
    def longestPalindrome(self, s: str) -> str:
        length = len(s)
        start_idx = 0
        end_idx = 0
        dp = []
        for _ in range(length):
            dp.append([False for _ in range(length)])
        for i in range(length):
            dp[i][i] = True
        for i in range(length - 1):
            if s[i] == s[i + 1]:
                dp[i][i + 1] = True
                start_idx = i
                end_idx = i + 1
        for size in range(2, length):
            for i in range(length):
                if i + size >= length:
                    break
                if s[i] == s[i + size] and dp[i + 1][i + size - 1]:
                    dp[i][i + size] = True
                    start_idx = i
                    end_idx = i + size
        return s[start_idx : end_idx + 1]


s = Solution()
print(s.longestPalindrome("babad"))
