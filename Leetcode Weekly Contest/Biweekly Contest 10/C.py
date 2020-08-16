class Solution:

    def __init__(self):
        self.table = []
        self.make_table()

    def dfs(self, dep, last, num):
        if dep == 0:
            self.table.append(num)
        else:
            if last + 1 <= 9:
                self.dfs(dep - 1, last + 1, num * 10 + last + 1)
            if last - 1 >= 0:
                self.dfs(dep - 1, last - 1, num * 10 + last - 1)

    def make_table(self):
        self.dfs(0, 0, 0)
        for i in range(9):
            for j in range(1, 10):
                self.dfs(i, j, j)
        self.dfs(9, 1, 1)
        self.table = sorted(set(self.table))

    def countSteppingNumbers(self, low: int, high: int) -> List[int]:
        return sorted([i for i in self.table if low <= i and i <= high])
