def dfs(now, idx, h):
    if now < idx: return -1
    size = 2 ** h - 1
    sub_size = size // 2
    left_node = now - sub_size - 1
    right_node = now - 1

    if idx == left_node or idx == right_node:
        return now
    if left_node >= idx:
        return dfs(left_node, idx, h-1)
    else:
        return dfs(right_node, idx, h-1)
    
def solution(h, q):
    # Your code here
    ans = []
    now_node = 2 ** h - 1 
    for x in q:
        ans.append(dfs(now_node, x, h))
    # print(ans)
    return ans

solution(3, [7, 3, 5, 1])