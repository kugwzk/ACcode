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
int n, p, a[maxn], sum[maxn];

int main()
{
#ifdef KUGWZK
    freopen("in.txt", "r", stdin);
#endif
    int T;
    scanf("%d",&T);
    for(int cas = 1; cas <= T; cas++) {

        scanf("%d %d", &n, &p);
        REP(i, 1, n + 1)
            scanf("%d", &a[i]);
        sort(a+1, a+1+n);
        REP(i,1,n+1)
            sum[i] = sum[i-1] + a[i];
        int ans = inf;
        // cout<<p<<endl;
        // cout<<n<<endl;
        for(int i = p; i <= n; i++) {
            // cout<<a[i]<<endl;
            // cout<<i<<endl;
            int tmp = a[i] * p - (sum[i] - sum[i-p]);
            // cout<<tmp<<endl;
            ans = min(tmp, ans);
        }
        printf("Case #%d: ", cas);
        printf("%d\n", ans);
    }
    return 0;
}