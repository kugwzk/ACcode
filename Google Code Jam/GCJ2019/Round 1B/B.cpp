#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#define maxn 100100
#define SIGMA 26
#define REP(i,x,y) for(int i=x;i<(y);i++)
#define RREP(i,x,y) for(int i=x;i>(y);i--)
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
int w;
ll small, big,ans[8];
int main() {
    int T;
    scanf("%d %d",&T, &w);
//cout<<T<<endl;
    for(int cas = 1; cas <= T; cas++){
        memset(ans,0, sizeof(ans));
        cout<<"200"<<endl;
        fflush(stdout);
        cin>>small;
        cout<<"50"<<endl;
        fflush(stdout);
        cin>>big;
        ans[4] = (small>>50);
        ans[5] = ((small - ans[4]*(1LL<<50)) >> 40);
        ans[6] = (((small - ans[4]*(1LL<<50)) - ans[5]*(1LL<<40)) >> 33);
        big -= (ans[4] << 12) + (ans[5] << 10) + (ans[6] << 8);
        ans[1] = (big >> 50);
        ans[2] = (big - ans[1]*(1LL<<50)) >> 25;
        ans[3] = (big - ans[1]*(1LL<<50) - ans[2]*(1LL<<25)) >> 16;
        for(int i=1;i<=6;i++) {
            cout << ans[i] << " ";
        }
        cout<<endl;
        fflush(stdout);
        ll res=0;
        cin>>res;

    }
}