from collections import deque


class Solution:
    def numSquares(self, n: int) -> int:
        squares = [i * i for i in range(1, int(n**0.5) + 1)]
        answer = {s: 1 for s in squares}

        if n in answer:
            return 1  # 이미 완전제곱수인 경우

        queue = deque([(n, 0)])  # (남은 수, 현재 단계)
        visited = set()

        while queue:
            num, step = queue.popleft()

            for square in squares:
                next_num = num - square
                if next_num < 0:
                    break
                if next_num == 0:
                    return step + 1  # 최소 개수 찾음
                if next_num not in visited:
                    visited.add(next_num)
                    queue.append((next_num, step + 1))
