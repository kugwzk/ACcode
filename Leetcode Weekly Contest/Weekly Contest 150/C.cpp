#define inf 0x3f3f3f3f
typedef pair<int,int> pii;
int Map[210][210];
pair<int,int> sea[210*210];
int cnt1=0,cnt2=0;
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid)
    {
        int n=grid.size(),ans=0;
        int dx[]={0,0,-1,1};
        int dy[]={-1,1,0,0};
        int Map[110][110],cnt=0;
        memset(Map,0,sizeof(Map));
        for (int i=0;i<n;i++)
            for (int j=0;j<n;j++) if (grid[i][j]==1)
                {
                    sea[++cnt]={i,j};
                    Map[i][j]=1;
                }
        queue<pair<int,int>> Q;
        for (int i=1;i<=cnt;i++) Q.push(sea[i]);
        while (!Q.empty())
        {
            pair<int,int> u=Q.front();
            Q.pop();
            for (int i=0;i<4;i++)
            {
                int xx=u.first+dx[i];
                int yy=u.second+dy[i];
                if (xx<0||xx>=n||yy<0||yy>=n) continue;
                if (!Map[xx][yy])
                {
                    Map[xx][yy]=Map[u.first][u.second]+1;
                    ans=max(ans,Map[xx][yy]);
                    Q.push({xx,yy});
                }
            }
        }
        return ans-1;
    }
};