//...START BY DOING WHAT IS NECESSARY, THEN WHAT IS POSSIBLE AND SUDDENLY YOU ARE DOING THE IMPOSSIBLE... 
#include <bits/stdc++.h>
using namespace std;typedef long long ll;
#define FAST_FURIER ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back
#define mk make_pair
#define sorta(v)        sort(v.begin(), v.end())
#define sortd(v)        sort(v.begin(), v.end(), comp)
#define rep(i,a,N)      for(ll i=a;i<N;i++)
#define rrep(i,a,N)     for(ll i=a;i>N;i--)
#define print(v)        for(ll ite=0;ite<v.size();ite++){cout<<v[ite]<<' ';}cout<<endl;
#define M 1000000007
 
bool comp(ll x,ll y){
    return x > y;
}
 
/*...............code starts here................*/
// C is first won in M
 
void solve(){
    ll m,n,k;
    cin >> n >> k;
    vector<ll> arr(n);
    rep(i,0,n){
        cin >> arr[i];
    }
    vector<pair<int,int> > p(n);
    ll val = arr[n-1], ind = n-1;
    p[n-1] = mk(n, val);
    for(ll i = n-2; i > -1; i--){
        if(arr[i] < val){
            ind = i+1;
            val = arr[i];
        }
        p[i] = mk(ind, val);
    }
    ll mx = -1e16;
    rep(i,0,n-1){
        ll a = i+1;
        ll b = p[i+1].first;
        val = p[i+1].second;
        mx = max(mx, a*b - k*(arr[i] | val));
    }
    cout << mx << endl;
}
int main() {
    FAST_FURIER;
    int tt=1;
    cin >> tt;
    while(tt--){
        solve();
    }
}
 