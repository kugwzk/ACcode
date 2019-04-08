#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
string s, a, b;
int main() {
    int T;
    scanf("%d",&T);
    for(int cas = 1; cas <= T; cas++){
        cin>>s;
        a=b="";
        int flag = 0;
        for(int i = 0; i<s.length(); i++){
            if(s[i] == '4'){
                a += "3";
                b += "1";
                flag = 1;
            }
            else {
                a += s[i];
                if (flag == 0) continue;
                else b += "0";
            }
        }
        if(b.length() == 0) b = "0";
        printf("Case #%d: ", cas);
        cout<< a << " " << b <<endl;
    }
}