class Solution {
public:
    int maxNumberOfApples(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int ans = 0, sum=0;
        for(int i=0; i<arr.size(); i++) {
            if(arr[i]+sum > 5000) break;
            sum += arr[i];
            ans ++;
        }
        return ans;
    }
};