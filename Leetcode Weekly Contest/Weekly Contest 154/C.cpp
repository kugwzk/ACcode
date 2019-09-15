class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        int n(arr.size());
        vector<long long> a;
        for (int x: arr)
            a.push_back(x);
        if (k > 3) {
            int s(0);
            for (int x: arr)
                s += x;
            a.push_back((long long)s * (k - 3));
            k = 3;
        }
        while (k-- > 1)
            for (int i(0); i < n; ++i)
                a.push_back(arr[i]);
        long long ans(0), sum(0);
        for (long long x: a) {
            sum += x;
            if (sum < 0)
                sum = 0;
            ans = max(ans, sum);
        }
        return int(ans % 1000000007);
    }
};