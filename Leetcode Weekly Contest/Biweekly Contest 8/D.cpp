class Solution {
public:
    int maximumNumberOfOnes(int width, int height, int sideLength, int maxOnes) {
        int ans(0), num_r(height / sideLength), rem_r(height % sideLength), num_c(width / sideLength), rem_c(width % sideLength);
        ans = num_r * num_c * maxOnes;
        ans += min(rem_r * rem_c, maxOnes) * (num_r + num_c + 1);
        if (rem_r * rem_c < maxOnes) {
            maxOnes -= rem_r * rem_c;
            if (num_r < num_c) {
                swap(num_r, num_c);
                swap(rem_r, rem_c);
                swap(width, height);
            }
            ans += min((sideLength - rem_r) * rem_c, maxOnes) * num_r;
            if ((sideLength - rem_r) * rem_c < maxOnes) {
                maxOnes -= (sideLength - rem_r) * rem_c;
                ans += min((sideLength - rem_c) * rem_r, maxOnes) * num_c;
            }
        }
        return ans;
    }
};