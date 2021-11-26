//...START BY DOING WHAT IS NECESSARY, THEN WHAT IS POSSIBLE AND SUDDENLY YOU ARE DOING THE IMPOSSIBLE... 
#include <bits/stdc++.h>
using namespace std;typedef long long ll;
#define FAST_FURIER ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back
#define mk make_pair
#define sorta(v)        sort(v.begin(), v.end())
#define sortd(v)        sort(v.begin(), v.end(), comp)
#define rep(i,a,N)      for(ll i=a;i<N;i++)
#define rrep(i,a,N)     for(ll i=a;i>N;i--)
#define print(v)        for(ll ite=0;ite<v.size();ite++){cout<<v[ite]<<' ';}cout<<endl;
#define M 1000000007
 
bool comp(ll x,ll y){
    return x > y;
}
 
/*...............code starts here................*/
// C is first won in M
 
void solve(){
    ll x, y; cin >> x >> y;
    ll p = (min(x, y) / 4);
    x -= 4 * p;
    y -= 4 * p;
    ll ans = p * 2;

    ll a = x, b = y;
    x = min(a, b);
    y = max(a, b);
    if(x == 1){
        if(y > 2) ans += 1;
    } else if(x == 2){
        if(y > 5) ans += 2;
        else ans += 1;
    } else if(x == 3){
        if(y > 8) ans += 3;
        else if(y >= 5) ans += 2;
        else ans += 1;
    }
    cout << ans << endl;
}
int main() {
    FAST_FURIER;
    int tt=1;
    cin >> tt;
    while(tt--){
        solve();
    }
}
 