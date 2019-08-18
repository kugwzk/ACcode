class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int Size = words.size();
        int ans = 0;
        map<char,int>ma;
        for(int i=0;i<Size;i++) {
            string t = words[i];
            int flag=1;
            ma.clear();
            for(int i=0;i<chars.length();i++) ma[chars[i]]+=1;
            //cout<<t<<endl;
            for(int j=0;j<t.length();j++) {
                if(!ma[t[j]]) {flag=0;break;}
                ma[t[j]]-=1;
            }
            if(flag) ans+=t.length();
        }
        return ans;
    }
};