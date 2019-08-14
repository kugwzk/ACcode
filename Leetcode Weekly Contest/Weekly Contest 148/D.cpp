#define REP(i,x,y) for(int i=x;i<(y);i++)
#define RREP(i,x,y) for(int i=x;i>(y);i--)
#define inf 0x3f3f3f3f
typedef long long ll;
typedef pair<int,int> pii;
int dp[1010], len;
class Solution {
public:
    string s;
    int check(int ed, int bg) {
        int tmp = ed-bg+1;
        //if(tmp>len/2) return 0;
        int pos = s.length()-bg;
        if(ed==3&&bg==2) {
            cout<<pos<<endl;
        }
        for(int i=ed; i >= bg; i--, pos--) {
            if(s[i] != s[pos]) return 0;

        }
        return 1;
    }
    int longestDecomposition(string text) {
        s=" ";
        s+=text;
        //cout<<s<<endl;
        memset(dp, -inf, sizeof(dp));
        len = text.length();
        dp[0] = 0;
        for(int i=1; i<=s.length()/2; i++) {
            cout<<i<<endl;
            for(int j=0; j<i; j++)
                if(dp[j]>=0 && check(i,j+1)) dp[i] = max(dp[i], dp[j]+1);
        }
        cout<<check(3,2)<<endl;
        int ans = 1;
        for(int i = 1; i <= len/2; i++) {
            cout<< i << " " << dp[i]<<endl;
            if(len%2) {
                if(dp[i]>=0) ans = max(ans, 2*dp[i]+1);
            }
            else {
                if(i==len/2&&dp[i]>=0) ans = max(ans, 2*dp[i]);
                else if(dp[i]>=0) ans = max(ans, 2*dp[i]+1);
            }
        }
        return ans;
    }
};