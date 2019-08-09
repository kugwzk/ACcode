#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <set>
#include <vector>
#include <queue>

#define maxn 100100
#define inf 0x3f3f3f3f
//#define KUGWZK
#define REP(i,x,y) for(int i=x;i<(y);i++)
#define RREP(i,x,y) for(int i=x;i>(y);i--)
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int r, c, ma[300][300], t[300][300];
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};
int sum[555][555];
int check(int limit) {
    memset(sum, 0, sizeof(sum));
    int maxx = max(r,c);
    int cnt = 0;
    REP(i, 1, r+1) {
        REP(j, 1, c+1) {
            if(t[i][j] <= limit) continue;
            cnt += 1;
            int xx = i+j, yy = maxx + i - j;
            int u = min(2*maxx, xx+limit);
            int d = max(1, xx-limit);
            int l = max(1, yy-limit);
            int r = min(2*maxx, yy+limit);
            sum[d][l] += 1;
            sum[u+1][l] -= 1;
            sum[d][r+1] -= 1;
            sum[u+1][r+1] += 1;
        }
    }
    REP(i, 1, 2*maxx+2) REP(j, 1, 2*maxx+2) sum[i][j] += sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
    REP(i, 1, 2*maxx+2) {
        REP(j, 1, 2*maxx+2) {
            if(sum[i][j] < cnt) continue;
            if((i+j-maxx)%2) continue;
            int x = (i + j - maxx) / 2;
            int y = i - x;
            if(x >= 1 && x <= r && y >= 1 && y <= c) return true;
        }
    }
    return false;
}
void bfs() {
    queue<pii> que;
    REP(i, 1, r+1)
        REP(j, 1, c+1)
            if(ma[i][j]) {
                que.push(make_pair(i, j));
                t[i][j] = 0;
            }
            else t[i][j] = inf;
    while(!que.empty()) {
        pii now = que.front(); que.pop();
        for(int i = 0; i < 4; i++) {
            int xx = now.first + dx[i];
            int yy = now.second + dy[i];
            if(xx <= 0 || xx > r || yy <= 0 || yy > c || t[xx][yy] < inf) continue;
            t[xx][yy] = t[now.first][now.second] + 1;
            que.push(make_pair(xx, yy));
        }
    }
}
int main()
{
#ifdef KUGWZK
    freopen("in.txt", "r", stdin);
#endif
    int T;
    scanf("%d",&T);
    for(int cas = 1; cas <= T; cas++) {
        scanf("%d %d", &r, &c);
        memset(ma, 0, sizeof(ma));
        memset(t, 0, sizeof(t));
        REP(i, 1, r+1) REP(j, 1, c+1) scanf("%1d", &ma[i][j]);
        bfs();
        int L = 0, R = r+c, ans = r+c;
        while(L <= R) {
            int mid = ((L+R) >> 1);
            if(check(mid)) {
                ans = mid;
                R = mid-1;
            }
            else L = mid+1;
        }

        printf("Case #%d: ", cas);
        printf("%d\n", ans);

    }
    return 0;
}