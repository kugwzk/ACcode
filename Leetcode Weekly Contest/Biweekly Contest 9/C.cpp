int ma[11000];
class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        memset(ma,0,sizeof(ma));
        for(int i=0;i<mat.size();i++) {
            for(int j=0;j<mat[i].size();j++) {
                ma[mat[i][j]]++;
            }
        }
        for(int i=1;i<=10000;i++) {
            if(ma[i]==mat.size()) return i;
        }
        return -1;
    }
};