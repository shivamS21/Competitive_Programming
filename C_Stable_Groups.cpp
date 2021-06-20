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

/*...............code starts here................*/
// C is first won in M
 
void solve(){
    ll m,n,k,x;
    cin >> n >> k >> x;
    vector<ll> vec(n);
    rep(i,0,n) cin >> vec[i];
    sorta(vec);
    vector<ll> p;
    rep(i,0,n-1){
        if(vec[i+1] - vec[i] > x){
            ll a = (vec[i+1] - vec[i])/x;
            if(vec[i] + x * a == vec[i+1])
            a -= 1;
            p.pb(a);
        }
    }
    sorta(p);
    ll ans = p.size() + 1;
    ll i = 0;
    while(i < p.size() and k > 0){
        if(p[i] <= k){
            k -= p[i];
            ans -= 1;
        }
        i += 1;
    }
    cout << ans << endl;
}
int main() {
    FAST_FURIER;
    int tt=1;
    // cin >> tt;
    while(tt--){
        solve();
    }
}
 