#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#define maxn 1100
#define SIGMA 26
#define REP(i,x,y) for(int i=x;i<(y);i++)
#define RREP(i,x,y) for(int i=x;i>(y);i--)
using namespace std;
typedef pair<int,int> pii;
int p,q;
pii a[maxn];
char d[maxn];
int x[100010],y[100010];
int main() {
    int T;
    scanf("%d",&T);
//cout<<T<<endl;
    for(int cas = 1; cas <= T; cas++){
        memset(a,0,sizeof(a));
        memset(d,0,sizeof(d));
        memset(x,0,sizeof(x));
        memset(y,0,sizeof(y));
        scanf("%d %d",&p,&q);
        for(int i=1;i<=p;i++) {
            scanf("%d %d %c",&a[i].first,&a[i].second,&d[i]);
            if(d[i]=='N'){
                y[a[i].second+1] += 1;
                x[0] += 1;
            }
            else if(d[i]=='S'){
                y[a[i].second] -= 1;
                y[0] += 1;
                x[0] += 1;
            }
            else if(d[i]=='E'){
                x[a[i].first+1] += 1;
                y[0] += 1;
            }
            else if(d[i]=='W'){
                x[a[i].first] -= 1;
                x[0] += 1;
                y[0] += 1;
            }
        }
        for(int i=0;i<=100000;i++) {
            x[i] += x[i-1];
            y[i] += y[i-1];
        }
        int posx = 0,posy=0;
        for(int i=0;i<=100000;i++) {
            if (x[i]>x[posx]) {
                posx = i;
            }
        }
        for(int i=0;i<=100000;i++) {
            if (y[i]>y[posy]) {
                posy = i;
            }
        }
        printf("Case #%d: ", cas);
        printf("%d %d\n", posx, posy);
    }
}