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
    ll target;
    cin >> n >> target;
    pair<ll, ll> arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i].first;
        arr[i].second = i+1;
    }
    sort(arr, arr+n);
    for(int i = 0; i <= n-3; i++){
        int j = i+1, k = n-1;
        ll sum;
        while(j < k){
            sum = target - arr[i].first;
            if(arr[j].first+arr[k].first == sum){
                cout << arr[i].second<<" "<<arr[j].second << " " << arr[k].second << endl;
                return;
            } else if(arr[j].first + arr[k].first < sum)
            j++;
            else k--;
        }
    }
    cout<<"IMPOSSIBLE\n";
    
}
int main() {
    FAST_FURIER;
    int tt=1;
    // cin >> tt;
    while(tt--) solve();
}
