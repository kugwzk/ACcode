#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#define maxn 1100
#define SIGMA 26
#define REP(i,x,y) for(int i=x;i<(y);i++)
#define RREP(i,x,y) for(int i=x;i>(y);i--)
using namespace std;
typedef pair<int,int> pii;
int n;

int del[100000+10];
int root,tot,Next[100000+10][SIGMA],cnt[100000+10];
char s[maxn][60];
inline int newnode(){
    REP(i,0,SIGMA) Next[tot][i]=-1;
    tot++;
    del[tot-1]=0;
    cnt[tot-1]=0;
    return tot-1;
}
inline int get_idx(char c){
    return c-'A';
}
inline void Insert(char s[]){
    int len=strlen(s);
    int now=root;
    cnt[now] += 1;
    RREP(i,len-1,-1){
        int tmp=get_idx(s[i]);
        if(Next[now][tmp]==-1)
            Next[now][tmp]=newnode();
        now=Next[now][tmp];
        cnt[now] += 1;
    }

}
int ans;
void dfs(int rt) {
    for (int i=0;i<SIGMA;i++) {
        if(Next[rt][i]==-1) continue;
        else {
            dfs(Next[rt][i]);
            del[rt] += del[Next[rt][i]];
        }
    }
    if (root!=rt) {
        cnt[rt] += del[rt];
        if (cnt[rt] >= 2) {
            ans += 2;
            cnt[rt] -= 2;
            del[rt] -= 2;
        }
    }
}
int main() {
    int T;
    scanf("%d",&T);
//cout<<T<<endl;
    for(int cas = 1; cas <= T; cas++){
        tot=0;
        root = newnode();
        ans =0;
        scanf("%d",&n);
        for (int i=1;i<=n;i++) {
            scanf(" %s", s[i]);
            Insert(s[i]);
        }
        dfs(root);

        printf("Case #%d: ", cas);
        printf("%d\n", ans);
    }
}