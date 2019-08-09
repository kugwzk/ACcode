//#define KUGWZK
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <set>
#define maxn 500100
#define inf 0x3f3f3f3f

#define REP(i,x,y) for(int i=x;i<(y);i++)
#define RREP(i,x,y) for(int i=x;i>(y);i--)
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int N, R, C, Sr, Sc;
string s;
int visr[maxn], visc[maxn];
set<pii>set_row[maxn], set_col[maxn];
void Insert(set<pii> &S, int now){
    int L = now, R = now;
    auto it = S.lower_bound(make_pair(now, now));
    if (it != S.begin()) {
        --it;
        pii tmp = (*it);
        if(now == tmp.second + 1) {
            L = tmp.first;
            S.erase(it);
        }
    }
    it = S.lower_bound(make_pair(now, now));
    if (it != S.end()) {
        pii tmp = (*it);
        if(now == tmp.first - 1){
            R = tmp.second;
            S.erase(it);
        }
    }
    S.insert(make_pair(L, R));
}
int get_L(set<pii> &S, int now) {
    int res = now - 1;
    auto it = S.upper_bound(make_pair(now, 0));
    if((*it).first == now) return now - 1;
    it--;
    res = (*it).first - 1;
    return res;
}
int get_R(set<pii> &S, int now) {
    auto it = S.upper_bound(make_pair(now, 0));
    if((*it).first == now) return (*it).second + 1;
    it--;
    int res = (*it).second + 1;
    return res;
}
int main()
{
#ifdef KUGWZK
    freopen("in.txt", "r", stdin);
#endif
    int T;
    scanf("%d",&T);
    for(int cas = 1; cas <= T; cas++) {
        scanf("%d %d %d %d %d", &N, &R, &C, &Sr, &Sc);
        REP(i,1,R+1) set_row[i].clear();
        REP(i,1,C+1) set_col[i].clear();
        Insert(set_row[Sr], Sc);
        Insert(set_col[Sc], Sr);
        cin>>s;
        for(int i = 0; i < s.length(); i++) {
            if (s[i] == 'W') {
                Sc = get_L(set_row[Sr], Sc);
            }
            if (s[i] == 'E') {
                Sc = get_R(set_row[Sr], Sc);
            }
            if (s[i] == 'N') {
                Sr = get_L(set_col[Sc], Sr);
            }
            if (s[i] == 'S') {
                Sr = get_R(set_col[Sc], Sr);
            }
            Insert(set_row[Sr], Sc);
            Insert(set_col[Sc], Sr);
        }
        printf("Case #%d: ", cas);
        cout<<Sr<<" "<<Sc<<endl;
    }
    return 0;
}