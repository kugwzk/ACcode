import queue
dx = [1,-1,0,0]
dy = [0,0,-1,1]
def solution(map):
    # Your code here
    start = (0,0,1,1)
    que = queue.Queue()
    que.put(start)
    row_size = len(map)
    col_size = len(map[0])
    vis = [[[0,0] for j in range(col_size)] for i in range(row_size)]
    vis[0][0][1]=1
    # print(vis)
    while not que.empty():
        
        now = que.get()
        # print(now)
        now_x = now[0]
        now_y = now[1]
        
        now_step = now[2]
        now_use = now[3]
        if now_x == row_size-1 and now_y == col_size-1:
            # print(now_step)
            return now_step
        for i in range(4):
            xx = now_x + dx[i]
            yy = now_y + dy[i]
            # print(xx)
            # print(yy)
            if xx < 0 or xx >= row_size or yy < 0 or yy >= col_size: continue
            if map[xx][yy] == 0 and vis[xx][yy][now_use] == 0:
                vis[xx][yy][now_use] = 1
                nxt_step=now_step+1
                que.put((xx, yy, nxt_step, now_use))
            if map[xx][yy] == 1 and now_use == 1 and vis[xx][yy][0] == 0:
                vis[xx][yy][0] = 1
                nxt_step=now_step+1
                que.put((xx, yy, nxt_step, 0))

solution([[0, 1, 1, 0], [0, 0, 0, 1], [1, 1, 0, 0], [1, 1, 1, 0]])