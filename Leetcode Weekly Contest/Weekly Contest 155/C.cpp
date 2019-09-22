typedef pair<int,int> pii;
vector<int>e[100010];
int vis[100010];
vector<int>kuai[100010];
vector<char>fuck[100010];
int cnt;

void dfs(int rt,int col,string& s) {
    vis[rt]=1;
    kuai[col].push_back(rt);
    fuck[col].push_back(s[rt]);
    for(int i=0;i<e[rt].size();i++) {
        if(vis[e[rt][i]]) continue;
        dfs(e[rt][i], col, s);
    }
}
class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        memset(vis,0,sizeof(vis));
        memset(e,0,sizeof(e));
        cnt = 0;
        for(int i=0;i<pairs.size();i++){
            int u=pairs[i][0];
            int v=pairs[i][1];
            e[u].push_back(v);
            e[v].push_back(u);
        }
        for(int i=0;i<s.length();i++) {
            if(vis[i]) continue;
            kuai[++cnt].clear();
            fuck[cnt].clear();
            dfs(i,cnt,s);
        }
        string ans = s;
        for(int i=1;i<=cnt;i++) {
            sort(kuai[i].begin(),kuai[i].end());
            sort(fuck[i].begin(),fuck[i].end());
            for(int j=0;j<kuai[i].size();j++) {
                //cout<<kuai[j]<<" "<<fuck[j]<<endl;
                ans[kuai[i][j]] = fuck[i][j];
            }
        }
        return ans;
    }
};