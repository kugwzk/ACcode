int dp[1100][1100];
class Solution {
public:
    bool isValidPalindrome(string s, int k) {
        memset(dp,0,sizeof(dp));
        string t = s;
        reverse(t.begin(), t.end());
        int n = s.length();
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(s[i]==t[j]) dp[i+1][j+1] = dp[i][j] + 1;
                else dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1]);
            }
        }
        bool ans = false;
        for(int i=1;i<=n;i++) {     //i-1
            for(int j=1;j<=n;j++) {     //j-1
                //cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
                if(dp[i][j] == 0) continue;
                int bg = i-2;
                int ed = n-1-j;
                if(bg >= ed) continue;
                if(2 * dp[i][j] >= n-k) return true;
                else if(bg+1<ed && 2*dp[i][j]+1 >= n-k) return true;

            }
        }
        return ans;
    }
};