class Solution {
public:
    int solve(const string &command, int x, int y) {
        int dx(0), dy(0);
        for (char c: command)
            if (c == 'U')
                ++dy;
            else if (c == 'R')
                ++dx;
        int s(min(x / dx, y / dy));
        int nx(dx * s), ny(dy * s), t(s * command.size());
        if (nx == x && ny == y)
            return t;
        for (int i(0); i < command.size() && dx <= x && dy <= y; ++i) {
            ++t;
            if (command[i] == 'U')
                ++ny;
            else if (command[i] == 'R')
                ++nx;
            if (nx == x && ny == y)
                return t;
        }
        return -1;
    }
    bool robot(string command, vector<vector<int>>& obstacles, int x, int y) {
        int t(solve(command, x, y));
        if (t < 0)
            return false;
        for (const auto &p: obstacles) {
            int nt(solve(command, p[0], p[1]));
            if (nt >= 0 && nt < t)
                return false;
        }
        return true;
    }
};
