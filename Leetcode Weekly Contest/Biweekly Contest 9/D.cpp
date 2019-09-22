class Solution {
public:
    bool check(int bound, const vector<int> &blocks, int split) {
        int last_idx(blocks.size() - 1), worker_num(1);
        while (last_idx >= 0 && last_idx + 1 > worker_num) {
            while (last_idx >= 0 && worker_num > 0 && blocks[last_idx] + split > bound) {
                --worker_num;
                --last_idx;
            }
            if (worker_num < 1 && last_idx >= 0)
                return false;
            worker_num *= 2;
            bound -= split;
        }
        return true;
    }

    int minBuildTime(vector<int> &blocks, int split) {
        sort(blocks.begin(), blocks.end());
        int l(1), r(200011), m;
        while (l < r) {
            m = l + (r - l) / 2;
            if (check(m, blocks, split))
                r = m;
            else
                l = m + 1;
        }
        return l;
    }
};
