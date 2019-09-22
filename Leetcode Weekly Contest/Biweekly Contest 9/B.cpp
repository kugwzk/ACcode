typedef pair<int,int> pii;
#define inf 0x3f3f3f3f
int dx[] = {-1,-1,1,1,2,2,-2,-2};
int dy[] = {-2,2,-2,2,1,-1,1,-1};
int vis[800][800];
int bfs(int x, int y) {
    queue<pii>que;que.push(make_pair(400,400));
    memset(vis,inf,sizeof(vis));
    vis[400][400]=0;
    while(!que.empty()) {
        pii now=que.front();que.pop();
        for(int i=0;i<8;i++) {
            int xx = dx[i]+now.first;
            int yy = dy[i]+now.second;
            if(xx<=0||xx>780||yy<=0||yy>780) continue;
            if(vis[xx][yy] == inf) {
                vis[xx][yy]=vis[now.first][now.second] + 1;
                que.push(make_pair(xx,yy));
            }
            
            if(vis[x][y]!=inf) break;
        }
    }
    return vis[x][y];
}
class Solution {
public:
    
    int minKnightMoves(int x, int y) {
        return bfs(400+x, 400+y);
    }
};