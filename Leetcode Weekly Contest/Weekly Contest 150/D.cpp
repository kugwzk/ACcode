class Solution {
public:
    string getmin(string s){
        int n=s.length();
        int i=0,j=1,k=0,t;
        while(i<n && j<n && k<n){
            t=s[(i+k)%n]-s[(j+k)%n];
            if (!t) k++;
            else{
                if (t<0) i+=k+1;
                else j+=k+1;
                if (i==j) j++;
                k=0;
            }
        }
        int ans=i<j?i:j;
        string tmp = "";
        for (int i=ans;i<n;i++) tmp+=s[i];
        return tmp;
    }
    string lastSubstring(string s) {
        return getmin(s);
    }
};