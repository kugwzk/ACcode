class Solution {
public:
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        static int f[2011];
        fill(f, f + arr1.size() + 5, arr1.size() + 10);
        arr1.push_back(0x3f3f3f3f);
        arr1.push_back(0);
        for (unsigned i = arr1.size() - 1; i > 0; --i)
            arr1[i] = arr1[i - 1];
        arr1[0] = 0xc0c0c0c0;
        sort(arr2.begin(), arr2.end());
        arr2.erase(unique(arr2.begin(), arr2.end()), arr2.end());
        f[0] = 0;
        for (int i = 1; i < arr1.size(); ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (arr1[j] < arr1[i] &&
                    lower_bound(arr2.begin(), arr2.end(), arr1[i]) - upper_bound(arr2.begin(), arr2.end(), arr1[j]) >= i - j - 1)
                    f[i] = min(f[i], f[j] + i - j - 1);
            }
        }
        return f[arr1.size() - 1] > arr1.size() - 2? -1: f[arr1.size() - 1];
    }
};