#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
string s, a, b;
int n;
int main() {
    int T;
    scanf("%d",&T);
    for(int cas = 1; cas <= T; cas++){
        scanf("%d",&n);
        cin >> s;
        a = "";
        for(int i = 0; i < s.length(); i++){
            if(s[i]=='S') a += "E";
            else a += "S";
        }
        printf("Case #%d: ", cas);
        cout<< a <<endl;
    }
}