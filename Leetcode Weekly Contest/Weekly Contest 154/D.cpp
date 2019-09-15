#define maxn 100010
#define inf 0x3f3f3f3f
struct Edge {
    int next, to;
}edge[3*maxn];
int head[maxn], dfn[maxn], low[maxn], cnt, tot;
vector<vector<int> >ans;
void addedge(int u, int v)
{
    edge[cnt].to = v;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}
void init(int n) {
    for (int i = 0; i <= n; ++i)
    {
        low[i] = dfn[i] = 0;
        head[i] = -1;
    }
    tot = 0;
    cnt = 1;
    ans.clear();
}
void tarjan(int u, int fa) {
    low[u] = dfn[u] = ++tot;
    for (int i = head[u]; i != -1; i = edge[i].next){
        int v = edge[i].to;
        if (!dfn[v])
        {
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] > dfn[u]){
                vector<int>tmp;tmp.clear();
                tmp.push_back(u);
                tmp.push_back(v);
                ans.push_back(tmp);
            }
        }
        else if(v!=fa)
            low[u] = min(low[u], dfn[v]);
    }
}
class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        init(n);
        for(int i=0;i<connections.size();i++) {
            addedge(connections[i][0], connections[i][1]);
            addedge(connections[i][1], connections[i][0]);
        }
        tarjan(0, -1);
        for(int i=0;i<n;i++) cout<<low[i]<<" "<<dfn[i]<<endl;
        return ans;
    }
};