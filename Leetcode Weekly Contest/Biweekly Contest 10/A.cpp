map<int,int>ma;
class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        ma.clear();
        vector<int>ans;ans.clear();
        for(int i=0;i<arr1.size();i++) ma[arr1[i]]++;
        for(int i=0;i<arr2.size();i++) ma[arr2[i]]++;
        for(int i=0;i<arr3.size();i++) ma[arr3[i]]++;
        for(auto it:ma){
            if(it.second == 3) ans.push_back(it.first);
        }
        return ans;
    }
};