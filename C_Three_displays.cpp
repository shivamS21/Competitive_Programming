//...START BY DOING WHAT IS NECESSARY, THEN WHAT IS POSSIBLE AND SUDDENLY YOU ARE DOING THE IMPOSSIBLE... 
#include <bits/stdc++.h>
using namespace std;typedef long long ll;
#define FAST_FURIER ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back
#define ppb pop_back
#define mk make_pair
#define sorta(v)        sort(v.begin(), v.end())
#define sortd(v)        sort(v.begin(), v.end(), comp)
#define rep(i,a,N)      for(ll i=a;i<N;i++)
#define rrep(i,a,N)     for(ll i=a;i>N;i--)
#define print(v)        for(ll ite=0;ite<v.size();ite++){cout<<v[ite]<<' ';}cout<<endl;
#define mem(v,a) 		 memset(v, a, sizeof(v))
#define M 1000000007
bool comp(ll x,ll y)
{
    return x > y;
}
 
/*...............code starts here................*/
// C is first won in M
vector<ll> s, c;
void solve(){
    ll m,n,k;
    cin >> n;
    s.resize(n);
    c.resize(n);
    rep(i,0,n) cin >> s[i];
    rep(i,0,n) cin >> c[i];
    ll ans = 1e15;
    rep(j,1,n-1){
        ll val = c[j];
        int f = 0;
        ll mni=1e15, mnk=1e15;
        rep(i,0,j){
            if(s[i] < s[j]){
                mni = min(mni, c[i]);
                f = 1;
            }
        }
        if(!f)
        continue;
        f = 0;
        rep(k,j+1,n){
            if(s[k] > s[j]){
                mnk = min(mnk, c[k]);
                f = 1;
            }
        }
        if(!f)
        continue;
        val += mni + mnk;
        ans = min(ans, val);
    }
    if(ans ==1e15)
    ans = -1;
    cout<<ans<<endl;
}
int main() {
    FAST_FURIER;
    int tt=1;
    // cin >> tt;
    while(tt--){
        solve();
    
    }
}
 
 
 
 
// g++ -std=c++17