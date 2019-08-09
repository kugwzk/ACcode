#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <set>
#include <vector>
#define maxn 100100
#define inf 0x3f3f3f3f
//#define KUGWZK
#define REP(i,x,y) for(int i=x;i<(y);i++)
#define RREP(i,x,y) for(int i=x;i>(y);i--)
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int n, p, a[maxn];
set<int>S;
int main()
{
#ifdef KUGWZK
    freopen("in.txt", "r", stdin);
#endif
    int T;
    scanf("%d",&T);
    for(int cas = 1; cas <= T; cas++) {
        scanf("%d %d", &n, &p);
        S.clear();
        REP(i,1,n+1) {
            scanf("%d", &a[i]);
            if(__builtin_popcount(a[i]) & 1)
                S.insert(i);
        }
        int pos,val;
        printf("Case #%d:", cas);
        REP(i,1,p+1) {
            scanf("%d %d", &pos, &val);
            pos += 1;
            if(__builtin_popcount(a[pos]) & 1)
                S.erase(pos);
            a[pos]=val;
            if(__builtin_popcount(a[pos]) & 1)
                S.insert(pos);
            if(S.size() % 2 == 0) {
                printf(" %d",n);
            }
            else {
                int bg = (*S.begin());
                int ed = (*(--S.end()));
                int ans = max(n-bg, ed-1);
                printf(" %d", ans);
            }
        }
        puts("");

    }
    return 0;
}