#define REP(i,x,y) for(int i=x;i<(y);i++)
#define RREP(i,x,y) for(int i=x;i>(y);i--)
typedef long long ll;
typedef pair<int,int> pii;
int a[20010];
int block, mode[200][200], Size, n, belong[20010];
int cnt2[20010], cnt[20010][200], ans[20010];
class MajorityChecker {
public:
    pii pp[233];
    void init(){
        REP(i,1,block+1){
            int L=Size*(i-1)+1;
            int R=min(Size*i,n);
            pp[i]=make_pair(L,R);
        }
    }
    MajorityChecker(vector<int>& arr) {
        memset(cnt,0,sizeof(cnt));
        memset(mode,0,sizeof(mode));
        memset(belong,0,sizeof(belong));
        memset(cnt2,0,sizeof(cnt2));
        memset(ans,0, sizeof(ans));
        n = arr.size();
        Size = (int)sqrt(n+0.5);
        block=n/Size;
        if(n%Size) block++;
        //  cout<<Size<<" "<<block<<endl;
        for(int i=1; i <= arr.size(); i++) {
            a[i] =arr[i-1];
            belong[i]=(i-1)/Size+1;
        }
        init();
        REP(i,1,block+1) {
            int maxx = 0;
            memset(cnt2,0,sizeof(cnt2));
            REP(j,pp[i].first,n+1) {
                cnt2[a[j]]++;
                if(cnt2[a[j]] > cnt2[maxx]) maxx = a[j];
                mode[i][belong[j]] = maxx;
            }
        }
        REP(i,1,n+1) cnt[a[i]][belong[i]] += 1;
        REP(i,1,20001) REP(j, 1, block+1) cnt[i][j] += cnt[i][j-1];
    }

    int query(int left, int right, int threshold) {
        left+=1;
        right+=1;
        // cout<<left<<" "<<right<<endl;
        int bl = belong[left];
        int br = belong[right];
        int maxx = 0, res = -1;
        //  cout<<bl<<" "<<br<<endl;
        if((bl+1)>(br-1)){         //同一块或者相邻
            REP(i,left,right+1){
                ans[a[i]]++;
                if(ans[a[i]]>ans[maxx]) maxx=a[i];
            }

            if (ans[maxx]>=threshold) res = maxx;
            REP(i,left,right+1) ans[a[i]]=0;
        }
        else {
            bl++;br--;
            //    cout<<bl<<" "<<br<<endl;
            maxx=mode[bl][br];
            //  cout<<maxx<<endl;
            REP(i,left,pp[bl-1].second+1) {
                ans[a[i]]++;
                if(ans[a[i]]+cnt[a[i]][br]-cnt[a[i]][bl-1]>ans[maxx]+cnt[maxx][br]-cnt[maxx][bl-1]) maxx=a[i];
            }
            //  cout<<maxx<<endl;
            //  cout<<right<<endl;
            REP(i,pp[br+1].first,right+1) {
                ans[a[i]]++;
                if(ans[a[i]]+cnt[a[i]][br]-cnt[a[i]][bl-1]>ans[maxx]+cnt[maxx][br]-cnt[maxx][bl-1]) maxx=a[i];
            }
            // cout<<maxx<<endl;
            // cout<<ans[maxx]<<endl;
            if (ans[maxx]+cnt[maxx][br]-cnt[maxx][bl-1]>=threshold) res = maxx;
            REP(i,left,pp[bl-1].second+1) ans[a[i]]=0;
            REP(i,pp[br+1].first,right+1) ans[a[i]]=0;
        }
        return res;
    }
};