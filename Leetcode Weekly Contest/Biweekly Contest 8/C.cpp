class Solution {
public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
        set<int> st[4];
        vector<int> ans;
        for (vector<int>::size_type i = 0; i < colors.size(); ++i)
            st[colors[i]].insert(i);
        for (const auto &q: queries) {
            set<int> &s(st[q[1]]);
            auto it = s.lower_bound(q[0]);
            int a = 0x3f3f3f3f;
            if (s.empty()) {
                a = -1;
            } else {
                if (it != s.end())
                    a = *it;
                if (it != s.begin() && abs(a - q[0]) > abs(*prev(it) - q[0]))
                    a = *prev(it);
                a = abs(a - q[0]);
            }
            ans.push_back(a);
        }
        return ans;
    }
};