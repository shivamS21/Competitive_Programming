#include <bits/stdc++.h>
using namespace std;typedef long long ll;
#define FAST_FURIER ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define sorta(v)        sort(v.begin(), v.end())
#define sortd(v)        sort(v.begin(), v.end(), comp)
#define M 1000000007
// bool comp(ll x,ll y) return x>y;
/*...............code starts here................*/
void solve(){
    int n; cin >> n;
    int arr[n];cout << n << endl;
    for(int i = 1; i < n+1; i++){
        arr[i-1] = i;
        cout << i << " ";
    } cout << endl;
    for(int i = 2; i <= n; i++){
        swap(arr[i-2], arr[i-1]);
        for(int i = 0; i < n; i++) cout << arr[i] << " ";
        cout << endl;
    }
}
int main() {
    FAST_FURIER;
    int tt=1;
    cin >> tt;
    while(tt--) solve();
}
