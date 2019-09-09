class Solution {
public:
    int countLetters(string S) {
        int len = S.length();
        int ans = 0;
        for(int i=0;i<len;i++) {
            ans += 1;
            for(int j=i+1;j<len;j++){
                if(S[j]!=S[i]) break;
                else ans++;
            }
        }
        return ans;
    }
};