class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int, int> cnt;
        for (int x: arr)
            ++cnt[x];
        set<int> frq;
        for (const auto &p: cnt)
            frq.insert(p.second);
        return frq.size() == cnt.size();
    }
};