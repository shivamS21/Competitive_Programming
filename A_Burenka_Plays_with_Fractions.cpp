#include <bits/stdc++.h>
using namespace std;typedef long long ll;
#define FAST_FURIER ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define sorta(v)        sort(v.begin(), v.end())
#define sortd(v)        sort(v.begin(), v.end(), comp)
#define M 1000000007
#define ll long long
bool comp(ll x, ll y){
    return x > y; }
/*...............code starts here................*/
int solve(){
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    if(!a && !c) return 0;
    if(!a or !c) return 1;
    if(a%b==0){
        a = a/b;
        b = 1;
    }
    if(c%d==0){
        c = c/d;
        d = 1;
    }

    if(b==d){
        if(a==c) return 0;
        if(a%c==0 or c%a==0) return 1;
        return 2; 
    }
    ll lcm = (b*d)/(__gcd(b, d));
    if(lcm == b){
        if(a==c) return 1;
        if(a%c==0 or c%a) return 2;
        else return 3;
    }
    if(lcm == d){
        if(a==c) return 1;
        if(c%a==0 or a%c==0) return 2;
        else return 3;
    }
    if(a==c) return 2;
    if(a%c==0 or c%a==0) return 3;
    return 4;
}
int main() {
    FAST_FURIER;
    int tt=1;
    cin >> tt;
    while(tt--) cout << solve() << endl;
}
