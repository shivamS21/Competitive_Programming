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
void solve(){
    ll n; cin >> n;
    ll no = 5, ans = 0;
    while(no <= n){
        ans += n/no;
        no *= 5;
    }
    cout<<ans<<endl;
    
}
int main() {
    FAST_FURIER;
    int tt=1;
    // cin >> tt;
    while(tt--) solve();
}
