map<char,int>ma;
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        ma.clear();
        for(int i=0;i<text.length();i++) {
            ma[text[i]]++;
        }
        int ans = ma['b'];
        ans = min(ans,ma['a']);
        ans = min(ans, ma['l']/2);
        ans = min(ans, ma['o']/2);
        ans = min(ans, ma['n']);
        return ans;
    }
};