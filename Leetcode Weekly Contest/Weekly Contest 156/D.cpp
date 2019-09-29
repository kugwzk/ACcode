typedef pair<int,int> pii;
int n;
map<pii,int>vis;
map<pii,int>dis;
class Solution {
public:
    int minimumMoves(vector<vector<int>>& grid) {
        n = grid.size();
        queue<pii>que;
        vis.clear();
        dis.clear();
        int Left = 0 * n + 0;
        int Right = 0 * n + 1;
        pii start = make_pair(Left, Right);
        que.push(start);
        vis[start] = 1;
        dis[start] = 0;
        while(!que.empty()) {
            pii now = que.front();que.pop();
            int ty = now.first % n;
            int tx = (now.first - ty)/n;
            int hy = now.second % n;
            int hx = (now.second - hy) / n;
            if(hx==tx && hy+1<n && grid[hx][hy+1] != 1) {   //you
                int nxth = hx*n+hy+1;
                int nxtt = hx*n+hy;
                pii nxt = make_pair(nxtt,nxth);
                if(vis.count(nxt) == 0) {
                    que.push(make_pair(nxtt, nxth));
                    vis[nxt] = 1;
                    dis[nxt] = dis[now] + 1;
                }
            }
            if(hy == ty && ty+1 < n && hy + 1 < n && grid[hx][hy+1] != 1 && grid[tx][ty+1] != 1) {
                int nxth = (hx)*n+hy + 1;
                int nxtt = (tx)*n+ty+1;
                pii nxt = make_pair(nxtt, nxth);
                if(vis.count(nxt) == 0) {
                    que.push(make_pair(nxtt, nxth));
                    vis[nxt] = 1;
                    dis[nxt] = dis[now] + 1;
                }
            }
            if(hy==ty && hx+1 < n && grid[hx+1][hy]!=1) {
                int nxth = (hx+1)*n+hy;
                int nxtt = hx*n+hy;
                pii nxt = make_pair(nxtt, nxth);
                if(vis.count(nxt) == 0) {
                    que.push(make_pair(nxtt, nxth));
                    vis[nxt] = 1;
                    dis[nxt] = dis[now] + 1;
                }
            }
            if(hx == tx && tx+1 < n && hx + 1 < n && grid[hx+1][hy] != 1 && grid[tx+1][ty] != 1) {
                int nxth = (hx+1)*n+hy;
                int nxtt = (tx+1)*n+ty;
                pii nxt = make_pair(nxtt, nxth);
                if(vis.count(nxt) == 0) {
                    que.push(make_pair(nxtt, nxth));
                    vis[nxt] = 1;
                    dis[nxt] = dis[now] + 1;
                }
            }
            if(hx == tx && hx + 1 < n && grid[hx+1][hy] != 1 && grid[tx+1][ty] != 1) {
                int nxth = (hx+1)*n+ty;
                int nxtt = now.first;
                pii nxt = make_pair(nxtt, nxth);
                if(vis.count(nxt) == 0) {
                    que.push(make_pair(nxtt, nxth));
                    vis[nxt] = 1;
                    dis[nxt] = dis[now] + 1;
                }
            }
            if(hy == ty && hy + 1 < n && grid[hx][hy+1] != 1 && grid[tx][ty+1] != 1) {
                int nxth = (tx)*n+ty+1;
                int nxtt = now.first;
                pii nxt = make_pair(nxtt, nxth);
                if(vis.count(nxt) == 0) {
                    que.push(make_pair(nxtt, nxth));
                    vis[nxt] = 1;
                    dis[nxt] = dis[now] + 1;
                }
            }
        }
        int endh = (n-1)*n+n-1;
        int endt = (n-1)*n+n-2;
        if(dis.count(make_pair(endt,endh))) return dis[make_pair(endt,endh)];
        else return -1;

    }
};
