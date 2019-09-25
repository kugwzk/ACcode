class Solution {
public:
    static const int V = 75, E = 311;
    int h[V], n[E], e[E], vt, et, mc[V];
    bool v[V];
    void ins(int f, int t) {
        n[++et] = h[f];
        h[f] = et;
        e[et] = t;
    }
    void add(int a, int b) {
        ins(a, b);
        ins(b, a);
    }
    bool dfs(int p) {
        int i;
        for (i = h[p]; i; i = n[i])
            if (!v[e[i]]) {
                v[e[i]] = true;
                if (mc[e[i]] < 0 || dfs(mc[e[i]])) {
                    mc[e[i]] = p;
                    return true;
                }
            }
        return false;
    }
    int domino(int n, int m, vector<vector<int>>& broken) {
        int i, j, ans(0);
        set<pair<int, int>> broken_set;
        for (const auto &p: broken)
            broken_set.insert(make_pair(p[0], p[1]));
        et = 0;
        vt = n * m;
        fill(h, h + vt + 5, 0);
        fill(mc, mc + vt + 5, -1);

        for (i = 0; i < n; ++i)
            for (j = 0; j < m; ++j)
                if (broken_set.find(make_pair(i, j)) == broken_set.end()) {
                    if (i + 1 < n && broken_set.find(make_pair(i + 1, j)) == broken_set.end())
                        add(i * m + j, (i + 1) * m + j);
                    if (j + 1 < m && broken_set.find(make_pair(i, j + 1)) == broken_set.end())
                        add(i * m + j, i * m + j + 1);
                }
        for (i = 0; i < vt; i += 2) {
            fill(v, v + vt + 5, false);
            if (dfs(i))
                ++ans;
        }
        return ans;
    }
};
