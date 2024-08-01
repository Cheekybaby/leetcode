class Solution:
    def recur(self, n: int, alice: bool) -> bool:
        if n == 0:
            return 
        for i in range(1, n):
            if n%i == 0:
                alice[0] = not alice[0]
                self.recur(n-i, alice)
                break

    def divisorGame(self, n: int) -> bool:
        alice = [True]
        self.recur(n, alice)
        return not alice[0]