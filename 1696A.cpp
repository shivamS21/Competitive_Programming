#include <bits/stdc++.h>
using namespace std;typedef long long ll;
#define FAST_FURIER ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define sorta(v)        sort(v.begin(), v.end())
#define sortd(v)        sort(v.begin(), v.end(), comp)
#define M 1000000007
bool comp(ll x, ll y){
    return x > y; }
/*...............code starts here................*/
void solve(){
    ll n, z; cin >> n >> z;

    vector<ll> arr(n);
    ll maxNo = 0;
    for(auto &it: arr){
        cin >> it;
        maxNo = max(maxNo, it);
        maxNo = max(maxNo, it | z);
    }
   
    cout << maxNo << endl;
}
int main() {
    FAST_FURIER;
    int tt=1;
    cin >> tt;
    while(tt--) solve();
}
