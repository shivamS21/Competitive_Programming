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
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];
    

    ll cur_or = 0;
    vector<bool> visited(n, false);
    ll i = 0;
    for(; i < min(n, (ll)31); i++){
        ll mx = 0, index = -1;
        for(int j = 0; j < n; j++){
            if(visited[j]) continue;
            if((cur_or | arr[j]) > mx){
                mx = cur_or | arr[j];
                index = j;
            }
        }
        visited[index] = true;
        cout << arr[index] << " ";
        cur_or = cur_or | arr[index];
    }
    for(int i = 0; i < n; i++){
        if(!visited[i]) cout << arr[i] << " ";
    }
    cout << endl;
}
int main() {
    FAST_FURIER;
    int tt=1;
    cin >> tt;
    while(tt--) solve();
}
