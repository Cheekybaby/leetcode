class Solution:
    def solve(self, s: str, index: int, memo: dict[int, int]) -> int:
        if index in memo:
            return memo[index]
        if index == len(s):
            return 1
        if s[index] == '0':
            return 0

        ways = self.solve(s, index+1, memo)
        if (index+1 < len(s)) and (s[index] == '1' or (s[index] == '2' and s[index+1] <= '6')):
            ways += self.solve(s, index+2, memo)

        memo[index] = ways
        return memo[index]


    def numDecodings(self, s: str) -> int:
        memo = {}
        return self.solve(s, 0, memo)