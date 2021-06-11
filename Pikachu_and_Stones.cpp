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
    cin >> n;
    vector<ll> vec(n);
    rep(i,0,n) cin >> vec[i];
    vector<ll> pre(n);
    pre[0] = vec[0];
    rep(i,1,n){
        if(vec[i] > pre[i-1])
        pre[i] = vec[i];
        else pre[i] = pre[i-1]+1;
    }

    vector<ll> suff(n);
    suff[n-1] = vec[n-1];
    rrep(i,n-2,-1){
        if(vec[i] > suff[i+1])
        suff[i] = vec[i];
        else suff[i] = suff[i+1] + 1;
    }

    vector<ll> a(n), b(n); a[0] = 0; b[n-1] = 0;
    rep(i,1,n) a[i] = a[i-1] + pre[i] - vec[i];
    rrep(i,n-2,-1) b[i] = b[i+1] + suff[i] - vec[i];

    ll mn = 1e17;
    rep(i,1,n-1){
        ll x = i;
        ll ans = 0;
        ans += a[x-1] + b[x+1];
        if(vec[x] < max(pre[x-1]+1, suff[x+1]+1))
        ans += max(pre[x-1]+1, suff[x+1]+1) - vec[x];
            
        mn = min(ans, mn);
    }
    cout << mn << endl;
}
int main() {
    FAST_FURIER;
    int tt=1;
    cin >> tt;
    while(tt--){
        solve();
    }
}
 