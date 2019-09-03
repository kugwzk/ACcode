#define maxn 10010
struct edge{
    int u,v,cost;
    edge(){}
    edge(int _u,int _v,int _c):u(_u),v(_v),cost(_c){}
}e[300010];
int tot = 0;
inline bool cmp(const edge& a,const edge& b){
    return a.cost<b.cost;
}
int par[maxn],ran[maxn];
inline void init(){
    for(int i=0;i<maxn;i++)
        par[i]=i;
    memset(ran,0,sizeof(ran));
}
inline int fin(int x){
    while(x!=par[x]) x=par[x]=par[par[x]];
    return x;
}
inline void unite(int x,int y){
    int fa1=fin(x);int fa2=fin(y);
    if(fa1==fa2) return ;
    if(ran[fa1]<ran[fa2]) {
        par[fa1]=fa2;
        ran[fa2]+=ran[fa1];
    }
    else {
        par[fa2]=fa1;
        ran[fa1]+=ran[fa2];
    }
}
class Solution {
public:

    int minCostToSupplyWater(int n, vector<int>& wells, vector<vector<int>>& pipes) {
        init();
        int st = 0;
        tot = 0;
        for(int i=0;i<wells.size();i++) {
            e[++tot] = edge(0, i+1, wells[i]);
        }
        for(int i=0;i<pipes.size();i++) {
            e[++tot] = edge(pipes[i][0], pipes[i][1], pipes[i][2]);
            e[++tot] = edge(pipes[i][1], pipes[i][0], pipes[i][2]);
        }
        sort(e+1,e+1+tot, cmp);

        int cnt=0, ans =0;
        for(int i=1;i<=tot;i++) {
            if(fin(e[i].u)!=fin(e[i].v)){
                unite(e[i].u,e[i].v);
                ans+=e[i].cost;
                cout<<e[i].u<<" "<<e[i].v<<" "<<e[i].cost<<endl;
                cnt++;
                if(cnt==n) break;
            }
        }
        return ans;
    }
};