typedef long long ll;
set<ll>uglynum;
int num[3];
ll gcd(ll a, ll b) {
    return b==0 ? a : gcd(b,a%b);
}
ll check(ll num, ll a, ll b, ll c) {
    ll ans = 0;
    if(a==b&&a==c) {
        return num / a;
    }
    else if(a==b) {
        ans = num/a+num/c-num/(a*c/gcd(a,c));
    }
    else if(b==c) {
        ans = num/a+num/c-num/(a*c/gcd(a,c));
    }
    else if(a==c) {
        ans = num/a+num/b-num/(a*b/gcd(a,b));
    }
    else {
        ll fuck = a*b/gcd(a,b);
        cout<<fuck<<endl;
        ans = num/a+num/b+num/c-num/(a*b/gcd(a,b))-num/(b*c/gcd(b,c))-num/(a*c/gcd(a,c))+num/(fuck*c/gcd(fuck,c));
    }
    return ans;
}
class Solution {
public:
    int nthUglyNumber(int n, int a, int b, int c) {
        ll L=1,R=2000000000,ans=-1;
        ll ab =gcd(a,b);
        ll bc = gcd(b,c);
        ll ac = gcd(a,c);
        ll abc = gcd(ab,bc);
        while(L<=R) {
            ll mid = ((L+R)>>1);
            if(check(mid,a,b,c)>=n) {
                ans = mid;
                R=mid-1;
            }
            else L=mid+1;
        }
        return ans;
    }
};