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
    ll n, k; cin >> n >> k;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    map<int,int> mp;
    for(auto i: arr){
        mp[i]+=1;
    }
    int fnfound = -1, found = 0;
    for(pair<int,int>p:mp){
        int diff = p.first - fnfound-1;
        if(diff<=0){
            fnfound = p.first;
        }
        if(found+diff >= k){
            cout << fnfound + k - found << endl;
            return;
        } else{
            found += diff;
        }
        fnfound = p.first;
    }
    int left = k - found;
    if(!left) cout << fnfound+1;
    else{
        cout << fnfound + k - found;
    }
}
int main() {
    FAST_FURIER;
    int tt=1;
    // cin >> tt;
    while(tt--) solve();
}
