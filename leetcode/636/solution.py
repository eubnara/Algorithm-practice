from typing import List


class Solution:
    def exclusiveTime(self, n: int, logs: List[str]) -> List[int]:
        prev_log = logs[0].split(":")
        callstack = []
        callstack.append(prev_log[0])
        time = {}
        for log in logs[1:]:
            cur_log = log.split(":")

            if cur_log[1] == "end":
                diff = int(cur_log[2]) - int(prev_log[2])
                if prev_log[1] == "start":
                    diff += 1
                time[cur_log[0]] = time.get(cur_log[0], 0) + diff
                callstack.pop()
            if cur_log[1] == "start":
                diff = int(cur_log[2]) - int(prev_log[2])
                if prev_log[1] == "end":
                    diff -= 1
                if len(callstack) > 0:
                    time[callstack[-1]] = time.get(callstack[-1], 0) + diff
                callstack.append(cur_log[0])
            print(time)
            prev_log = cur_log
        ans = []
        for i in range(0, n):
            ans.append(time[str(i)])
        return ans


n = 2
logs = ["0:start:0", "0:start:2", "0:end:5", "1:start:6", "1:end:6", "0:end:7"]

n = 3
logs = [
    "0:start:0",
    "0:end:0",
    "1:start:1",
    "1:end:1",
    "2:start:2",
    "2:end:2",
    "2:start:3",
    "2:end:3",
]

sol = Solution()
print(sol.exclusiveTime(n, logs))
