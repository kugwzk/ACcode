class Solution:

    def _solve(self, s):
        if '(' not in s:
            return ''.join(reversed(s))
        stack = []
        i = 0
        while i < len(s):
            if s[i] == '(':
                stack.append(i)
            elif s[i] == ')':
                s = s[:stack[-1]] + self._solve(s[stack[-1] + 1: i]) + s[i + 1:]
                stack.pop()
                i -= 2
            i += 1
        return s

    def reverseParentheses(self, s: str) -> str:
        if '(' not in s:
            return s
        return self._solve(s)
