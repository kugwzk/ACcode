#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#define maxn 100100  
#define inf 0x3f3f3f3f
#define SIGMA 26  
#define REP(i,x,y) for(int i=x;i<(y);i++)
#define RREP(i,x,y) for(int i=x;i>(y);i--)
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
int n,k;
int c[maxn],d[maxn];
int sta[maxn],L[maxn],R[maxn];
int maxx[maxn<<2], minn[maxn<<2];
inline void pushup(int rt){
    maxx[rt] = max(maxx[rt<<1], maxx[rt<<1|1]);
}
void build(int l, int r, int rt) {
    if (l == r) {
        maxx[rt] = d[l];
        return;
    }
    int m = ((l+r)>>1);
    build(lson);
    build(rson);
    pushup(rt);
}
inline int query_max(int ql, int qr, int l, int r, int rt) {
    if (ql <= l && qr >= r) return maxx[rt];
    int m = ((l+r)>>1);
    int res = 0;
    if(ql <= m) res = max(res, query_max(ql, qr, lson));
    if(qr > m) res = max(res, query_max(ql, qr, rson));
    return res;
}

int main() {
    int T;
    scanf("%d",&T);
//cout<<T<<endl;
    for(int cas = 1; cas <= T; cas++){
        scanf("%d %d",&n,&k);
        for(int i=1;i<=n;i++) scanf("%d",&c[i]);
        for(int i=1;i<=n;i++) scanf("%d",&d[i]);
        build(1, n, 1);
        memset(L,0,sizeof(L));
        memset(R,0,sizeof(R));
        int top = 0;
        L[1] = 1;
        sta[++top] = 1;
        for(int i = 2; i <= n; i++) {
            while (top && c[sta[top]] < c[i]) top--;
            //printf("%d %d\n", c[sta[top]], c[i]);
            if (top && c[sta[top]] >= c[i]) {
                L[i] = sta[top] + 1;
                sta[++top] = i;
            } else {
                L[i] = 1;
                sta[++top] = i;
            }
        }
        top = 0;
        sta[++top] = n;
        R[n] = n;
        for(int i = n-1; i > 0; i--) {
            while(top && c[sta[top]] <= c[i]) top--;
            if(top && c[sta[top]] > c[i]) {
                R[i] = sta[top] - 1;
                sta[++top] = i;
            }
            else {
                R[i] = n;
                sta[++top] = i;
            }
        }
        /*
        for(int i = 1; i <= n; i++) {
            printf("%d %d\n",L[i],R[i]);
        }*/
        ll ans = 0;
        for(int i = 1; i <= n; i++) {
            //cout<<i<<endl;
            int need_max = c[i] + k, need_min = c[i] - k;
            int lpos = 1, rpos = i;
            int need_lpos = i + 1;
            while (lpos <= rpos) {
                int mid = ((lpos + rpos) >> 1);
                int tmp = query_max(mid, i, 1, n, 1);
                if (tmp <= need_max) {
                    need_lpos = mid;
                    rpos = mid - 1;
                } else
                    lpos = mid + 1;
            }
            int need_rpos = i;
            lpos = i, rpos = n;
            while (lpos <= rpos) {
                int mid = ((lpos + rpos) >> 1);
                int tmp = query_max(i, mid, 1, n, 1);
                if (tmp <= need_max) {
                    need_rpos = mid;
                    lpos = mid + 1;
                } else rpos = mid - 1;
            }
            ll ans1 = 1LL * (i - max(need_lpos, L[i]) + 1) * (min(need_rpos, R[i]) - i + 1);
            if (ans1 == 0) continue;
            lpos = 1, rpos = i;
            need_lpos = i + 1;
            need_rpos = i;
            while (lpos <= rpos) {
                int mid = ((lpos + rpos) >> 1);
                int tmp = query_max(mid, i, 1, n, 1);
                if (tmp < need_min) {
                    need_lpos = mid;
                    rpos = mid - 1;
                } else lpos = mid + 1;
            }
            lpos = i, rpos = n;
            while (lpos <= rpos) {
                int mid = ((lpos + rpos) >> 1);
                int tmp = query_max(i, mid, 1, n, 1);
                if (tmp < need_min) {
                    need_rpos = mid;
                    lpos = mid + 1;
                } else rpos = mid - 1;
            }
            ll ans2 = 1LL * (i - max(need_lpos, L[i]) + 1) * (min(need_rpos, R[i]) - i + 1);
            ans += ans1 - ans2;
        }
        printf("Case #%d: ", cas);
        cout << ans <<endl;
    }
}