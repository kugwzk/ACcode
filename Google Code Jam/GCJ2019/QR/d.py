import math
import sys
T = int(input())
for cas in range(1, T+1):
    N, B, F = map(int, input().strip().split())
    F = 4
    ans = []
    output = []
    for i in range(F):
        tmp = [0 for _ in range(N)]
        for j in range(N):
            tmp[j] = chr(ord('0') +((j & (1 << i)) >> i))
        output.append(tmp)
        #print(tmp)
        tmp = ''.join(tmp)
        print(tmp)
        sys.stdout.flush()
        ans.append(input().strip())
    #print(ans)
    #print(output)
    pre = 0
    need = []
    for i in range(N - B):
        num = 0
        for j in range(4):
            num += ((ord(ans[j][i]) - ord('0')) << j)
        while num != pre % 16:
            need.append(pre)
            pre += 1
        pre += 1
    while N % 16 != pre % 16:
        need.append(pre)
        pre += 1
    print(str(' '.join(map(str, need))))
    sys.stdout.flush()
    verdict = map(int, input().strip())
