#define maxn 30010
typedef pair<int,int> pii;
vector<int>e[maxn], e2[maxn];
vector<int>ans;
int in[maxn],in2[maxn];
int vis[maxn], vis2[maxn];
class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        ans.clear();
        memset(vis,0,sizeof(vis));
        memset(in2,0,sizeof(in2));
        memset(in,0,sizeof(in));
        memset(e,0,sizeof(e));
        memset(e2,0,sizeof(e2));
        memset(vis2,0,sizeof(vis2));
        for(int i=0;i<n;i++) {
            int u = i;
           if(group[u] != -1)
                e2[group[u]].push_back(u);
            for(int j=0;j<beforeItems[i].size();j++) {
                int v = beforeItems[i][j];
                e[v].push_back(u);
                if(group[v] == group[u] || group[u] == -1 || group[v] == -1) continue;
                in2[group[u]]++;
            }
            in[u]+=beforeItems[i].size();
        }
        queue<int>que;
        for(int i=0;i<n;i++) {
            if(in[i]==0 && (group[i] == -1 || in2[group[i]] == 0)) {
                que.push(i);
                vis[i] = 1;
            }    
        }
        
        while(!que.empty()) {
            int now = que.front(); que.pop();
            if(group[now] == -1) {
                ans.push_back(now);
                for(int i=0; i<e[now].size(); i++) {
                    int nxt = e[now][i];
                    in[nxt]--;
                    if(in[nxt] == 0 && (group[nxt]==-1 || in2[group[nxt]] == 0)) {
                        if(vis[nxt] == 0) {
                            que.push(nxt);
                            vis[nxt] = 1;
                        }
                    }
                }
            }
            else if(vis2[group[now]] == 0){
                queue<int>zunei;
                for(int i = 0; i < e2[group[now]].size(); i++) {
                    int nxt = e2[group[now]][i];             
                    if(in[nxt] == 0) {
                        zunei.push(nxt);
                    }
                }
                while(!zunei.empty()) {
                    int now2 = zunei.front();zunei.pop();
                    vis[now2] = 1;
                    ans.push_back(now2);
                    for(int i = 0; i < e[now2].size();i++) {
                        int nxt = e[now2][i];
                        in[nxt] --;
                        if(group[nxt] != -1 && group[nxt] == group[now2]) {
                            if(in[nxt] == 0) zunei.push(nxt);
                        }
                        else if(group[nxt] == -1) {
                            if(vis[nxt] == 0 && in[nxt] == 0) {
                                vis[nxt] = 1;
                                que.push(nxt);
                            }
                        }
                        else if(group[nxt] != group[now2]) {
                            in2[group[nxt]]--;
                            if(in2[group[nxt]] == 0) {
                                for(int j=0;j<e2[group[nxt]].size();j++) {
                                    int tmp = e2[group[nxt]][j];
                                    if(vis[tmp] == 0 && in[tmp] == 0) {
                                        vis[tmp] = 1;
                                        que.push(tmp);
                                    }
                                }
                            }
                        }
                    }
                }
                vis2[group[now]] = 1;
            }
        }
        if(ans.size() == n)
            return ans;
        return {};
    }
};