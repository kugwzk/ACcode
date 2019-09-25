
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define maxn 50050
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define mod 1000000007
vector<int>e[maxn];
int L[maxn],R[maxn],dfs_clock;
void dfs(int st){
    L[st]=++dfs_clock;
    for(int i=0;i<e[st].size();i++)
        dfs(e[st][i]);
    R[st]=dfs_clock;
}
ll Add[maxn<<2], sum[maxn<<2];
void pushdown(int rt,int l, int r){
    if(Add[rt]!=0){
        Add[rt<<1|1]=(Add[rt<<1|1]+Add[rt])%mod;
        Add[rt<<1] = (Add[rt<<1]+Add[rt])%mod;
        int m = (l+r)>>1;
        sum[rt<<1|1] = (sum[rt<<1|1] + Add[rt]*(r-m)%mod) % mod;
        sum[rt<<1] = (sum[rt<<1] + Add[rt]*(m-l+1)%mod) % mod;
    }
    Add[rt]=0;
}
inline void pushup(int rt){
    sum[rt]=(sum[rt<<1]+sum[rt<<1|1]) % mod;
}
void build(int l,int r,int rt){
    Add[rt]=0;
    if(l==r)   {    sum[rt]=0; return ;}
    int m=((l+r)>>1);
    build(lson);build(rson);
    pushup(rt);
}
inline void update(int L,int R,ll val,int l,int r,int rt){
    if(L<=l&&r<=R){
        Add[rt] = (Add[rt]+val)%mod;
        sum[rt] = (sum[rt]+(val * 1LL * (r-l+1)%mod))%mod;
        return ;
    }
    int m=((l+r)>>1);
    pushdown(rt,l,r);
    if(L<=m) update(L,R,val,lson);
    if(R>m) update(L,R,val,rson);
    pushup(rt);
    return ;
}
inline int query(int ql,int qr,int l,int r,int rt){
    if(ql<=l&&r<=qr){
        return sum[rt]%mod;
    }
    int m=((l+r)>>1);
    pushdown(rt,l,r);
    ll res=0;
    if(ql<=m)  res= (res + query(ql,qr,lson))%mod;
    if(qr>m) res = (res+query(ql,qr,rson))%mod;
    pushup(rt);
    return res%mod;
}
class Solution {
public:
    vector<int> bonus(int n, vector<vector<int>>& leadership, vector<vector<int>>& operations) {
        dfs_clock = 0;
        memset(L,0,sizeof(L));
        memset(R,0,sizeof(R));
        for(int i = 0;i<maxn;i++) e[i].clear();
        memset(Add,0,sizeof(Add));
        memset(sum,0,sizeof(sum));
        for(int i = 0;i < leadership.size(); i++) {
            e[leadership[i][0]].push_back(leadership[i][1]);
        }
        int root = 1;
        dfs(root);
        build(1,n,1);
        vector<int>ans;ans.clear();
        for(int i=0;i<operations.size();i++) {
            int op = operations[i][0];
            int x = operations[i][1];
            if(op==3) {
                int l = L[x];
                int r = R[x];
                //cout<<l<<" "<<r<<endl;
                ans.push_back(query(l,r,1,n,1));
            }
            else if(op==1){
                int l = L[x];
                int r = L[x];
                //cout<<l<<" "<<r<<endl;
                update(l,r,(ll)operations[i][2],1,n,1);
                //cout<<query(l,r,1,n,1)<<endl;
            }
            else if(op==2) {
                int l = L[x];
                int r = R[x];
                //cout<<l<<" "<<r<<endl;
                update(l,r,(ll)operations[i][2],1,n,1);
                //cout<<query(l,r,1,n,1)<<endl;
            }
        }
        return ans;
    }
};