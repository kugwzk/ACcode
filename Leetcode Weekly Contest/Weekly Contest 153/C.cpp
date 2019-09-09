#define inf 0x3f3f3f3f
int dp[100005][2];

class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int flag = 0;
        memset(dp,-inf,sizeof(dp));
        dp[0][0] = arr[0];
        dp[0][1] = -inf;
        for(int i = 1; i<arr.size();i++) {
            if(dp[i-1][1]+arr[i] > 0)
                dp[i][1] = dp[i-1][1] + arr[i];
            if(dp[i-1][0] > 0)
                dp[i][1] = max(dp[i][1], dp[i-1][0]);

            if(dp[i-1][0]+arr[i] > 0)
                dp[i][0] = max(dp[i][0], dp[i-1][0]+arr[i]);
            dp[i][0] = max(dp[i][0], arr[i]);

        }
        int maxx = -inf;
        for(int i=0;i<arr.size();i++) {
            maxx=max(maxx,dp[i][0]);
            maxx=max(maxx,dp[i][1]);
            cout<<dp[i][0]<<" "<<dp[i][1]<<endl;
        }
        return maxx;
    }
};