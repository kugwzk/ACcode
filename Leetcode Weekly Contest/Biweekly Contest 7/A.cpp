class Solution {
public:
    map<char,int>ma;
    int calculateTime(string keyboard, string word) {
        ma.clear();
        for(int i=0;i<keyboard.length();i++) {
            ma[keyboard[i]] = i;
        }
        int pre=0,ans=0;
        for(int i=0;i<word.length();i++) {
            cout<<ma[word[i]]<<endl;
            ans+=abs(ma[word[i]]-pre);
            cout<<pre<<endl;
            cout<<ans<<endl;
            pre=ma[word[i]];
        }
        return ans;
    }
};