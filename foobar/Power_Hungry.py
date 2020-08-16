def solution(xs):
    # Your code here
    fu = []
    zheng = []
    zero = []
    ans = 0
    if len(xs) == 1: return xs[0]
    for x in xs:
        # print(x)
        if x < 0:
            fu.append(x)
        if x == 0: 
            zero.append(x)
        if x > 0:
            zheng.append(x)
    # print("****")
    max_zero = 0
    max_fu = 1
    # print(fu)
    fu = sorted(fu)
    # print(fu)
    if len(fu) % 2 == 1:
        for num in fu[:-1]:
            max_fu = max_fu * num
    else:
        for num in fu:
            max_fu = max_fu * num
    max_zheng = 1
    for num in zheng:
        max_zheng = max_zheng * num
    print(max_zheng)
    print(max_fu)
    print(zheng)
    print(fu)
    if len(zero) == len(xs): return 0
    elif len(zero)+len(fu) == len(xs):
        if len(fu) == 1:
            return 0
        else: return max_fu
    else:
        # print("fuck")
        
        return max_zheng*max_fu
    
print(solution([-2, -3, 4, -5]))