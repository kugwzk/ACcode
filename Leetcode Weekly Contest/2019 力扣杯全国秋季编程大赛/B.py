class Solution:
    def fraction(self, cont: List[int]) -> List[int]:
        u = cont[-1]
        d = 1
        cont.pop(-1)
        while len(cont) > 0:
            u, d = d, u
            u += cont[-1] * d
            g = math.gcd(u, d)
            u //= g
            d //= g
            cont.pop(-1)
        return [u, d]
