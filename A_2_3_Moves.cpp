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
    if(n==1) cout << 2;
    else if(n==2) cout << 1; 
    else if(n==3) cout << 1;
    else if(n%3==1) cout << n/3 +1;
    else if(n%3==2) cout << n/3+1;
    else cout << n/3;
    cout << endl;
}
int main() {
    FAST_FURIER;
    int tt=1;
    cin >> tt;
    while(tt--) solve();
}
