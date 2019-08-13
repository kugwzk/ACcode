int dp[10000][10000];

class Solution {
public:
    int fuck[30];
    int maxRepOpt1(string text) {
        int ans = 0;
        memset(fuck,0, sizeof(fuck));
        for(int i=0;i<text.length();i++) {
            fuck[text[i]-'a']++;
        }
        for (int i = 0; i < text.length();i++) {
            int flag = 0;
            int cnt = 1;
            for(int j = i+1; j < text.length(); j++) {
                if (text[i] != text[j]) {
                    if (flag) break;
                    else {
                        flag = 1;
                        cnt++;
                    }
                }
                else cnt += 1;
            }
            if (fuck[text[i]-'a'] < cnt)
                cnt-=1;
            ans = max(cnt, ans);
        }
        return ans;
    }
};