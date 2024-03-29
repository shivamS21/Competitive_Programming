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
    ll target; cin >> n >> target;
    pair<long long,ll> arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i].first;
        arr[i].second = i+1;
    }
    sort(arr, arr+n);
    int i = 0, j = n-1;
    while(i < j){
        if(arr[i].first+arr[j].first == target){
            cout << arr[i].second << " " << arr[j].second << endl;
            return;
        } else if(arr[i].first + arr[j].first < target)
        i++;
        else j--;
    }
    cout << "IMPOSSIBLE\n";
}
int main() {
    FAST_FURIER;
    int tt=1;
    // cin >> tt;
    while(tt--) solve();
}
