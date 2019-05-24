#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <cmath>

#define maxn 10050
#define inf 0x3f3f3f3f
#define SIGMA 26
#define REP(i,x,y) for(int i=x;i<(y);i++)
#define RREP(i,x,y) for(int i=x;i>(y);i--)
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
using namespace std;
typedef pair<long, long> pii;
typedef long long ll;
int n, c[maxn], r[maxn];


int main() {
    int T;
    scanf("%d",&T);
//cout<<T<<endl;
    for(int cas = 1; cas <= T; cas++){
        scanf("%d", &n);
        REP(i,1,n+1) scanf("%d %d", &r[i], &c[i]);
        int maxr = 0, minr = inf;
        for(int i = 1; i <= n; i++) {
            maxr = max(maxr, r[i]);
            minr = min(minr, r[i]);
        }
        int ansr = (maxr - minr - 1.0) / 2 + 1;
        //cout<<ansr<<endl;
        int maxc = 0, minc = inf;
        for(int i = 1; i <= n; i++) {
            maxc = max(maxc, c[i]);
            minc = min(minc, c[i]);
        }
        int ansc = (maxc - minc - 1.0) / 2 + 1;
        //cout<<ansc<<endl;
        printf("Case #%d: ", cas);
        printf("%d\n", max(ansr, ansc));
    }
}