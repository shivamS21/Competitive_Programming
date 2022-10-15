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
    vector<int> arr(n-1);
    for(auto &it: arr) cin >> it;
    for(int i = 0; i < n-1; i++){
        if(abs(arr[i]) > n-1) continue;
        arr[abs(arr[i])-1] *= -1;
    }
    for(int i = 0; i < n-1; i++){
        if(arr[i] > 0)
        {cout<< i+1;
        return;}
    }
    cout<< n;
}
int main() {
    FAST_FURIER;
    int tt=1;
    // cin >> tt;
    while(tt--) solve();
}
