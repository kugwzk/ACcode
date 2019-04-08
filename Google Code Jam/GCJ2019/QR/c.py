import math

T = int(input())
for cas in range(1, T+1):
    n, l = map(int, input().strip().split())
    a = list(map(int, input().strip().split()))
    pos = 0
    while pos < len(a):
        if a[pos] == a[pos+1]:
            pos += 1
        else:
            break
    prime = []
    gcds = []
    tmp = math.gcd(a[pos], a[pos+1])
    prime.append(a[pos]//tmp)
    gcds.append(a[pos]//tmp)
    for i in range(pos+1, l):
        prime.append(tmp)
        gcds.append(tmp)
        tmp = a[i]//tmp
    prime.append(tmp)
    gcds.append(tmp)
    prime = sorted(set(prime))
    s = ""
    tmp2 = gcds[0]
    for i in range(pos, 0, -1):  #包含pos
        tmp2 = a[i] / tmp2
        idx = prime.index(tmp2)
        s += chr(ord('A') + idx)

    s = s[::-1]
    for i in range(len(gcds)):
        idx = prime.index(gcds[i])
        s += chr(ord('A') + idx)

    print("Case #%d: " % cas, end="")
    print(s)