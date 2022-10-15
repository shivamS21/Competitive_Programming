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
    vector<ll> arr(n);
    for(auto &it: arr) cin >> it;
    ll moves = 0;
    for(int i = 1; i < n; i++){
        if(arr[i] < arr[i-1]){
            moves += abs(arr[i]-arr[i-1]);
            arr[i] = arr[i-1];
        }
    }

    cout<< moves;
    
}
int main() {
    FAST_FURIER;
    int tt=1;
    // cin >> tt;
    while(tt--) solve();
}
