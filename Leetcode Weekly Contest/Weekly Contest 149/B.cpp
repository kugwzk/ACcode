int dp[10000][10000];
class Solution {
public:

#define mod 1000000007
#include <cstring>
int numRollsToTarget(int d, int f, int target) {
    memset(dp,0,sizeof(dp));
    dp[0][0] = 1;
    for (int i=1;i<=d;i++) {
        int maxx = f*i;
        int minn = i;
        for(int j=minn;j<=maxx;j++) {
            for(int k=1;k<=min(j,f);k++) {
                dp[i][j] = (dp[i-1][j-k] + dp[i][j]) % mod;
            }
        }
    }
    return dp[d][target];
}
};