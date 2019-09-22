class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<vector<int> > ans; ans.clear();
        int minn =0x3f3f3f3f;
        for(int i=0;i<arr.size()-1;i++) {
            int tmp = abs(arr[i+1]-arr[i]);
            if(tmp<minn) {
                ans.clear();
                vector<int>fuck;fuck.clear();
                fuck.push_back(arr[i]);
                fuck.push_back(arr[i+1]);
                ans.push_back(fuck);
                minn = tmp;
            }
            else if(tmp==minn) {
                vector<int>fuck;fuck.clear();
                fuck.push_back(arr[i]);
                fuck.push_back(arr[i+1]);
                ans.push_back(fuck);
            }
        }
        return ans;
    }
};