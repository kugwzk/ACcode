class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        vector<int> c(s.size(), 0);
        for (int i(0); i < s.size(); ++i)
            c[i] = abs(s[i] - t[i]);
        int ans(0), l(0), r(-1), sum(0);
        for (; l < c.size(); sum -= c[l++]) {
            if (r < l) {
                r = l;
                sum = 0;
            }
            while (r < c.size() && sum + c[r] <= maxCost)
                sum += c[r++];
            ans = max(ans, r - l);
        }
        return ans;
    }
};