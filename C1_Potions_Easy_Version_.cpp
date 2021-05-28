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
ll dp[200005];
vector<ll> vec(200005);
ll n;
ll calc(ll i, ll val){
    if(i == n){
        return 0;
    }
    ll &res = dp[i];

    if(res != -1)
    return res;

    if(vec[i] < 0){
        ll a = 0, b = 0;
        if(val+vec[i]>=0){
            a = 1 + calc(i+1, vec[i] + val);
        b = calc(i+1, val);
        }
        else a = calc(i+1, val);
        res = max(a, b);
    }
    else{
        res = 1 + calc(i+1, val);
    }
    return res;

}
void solve(){
    cin >> n;
    rep(i,0,n) cin >> vec[i];
    memset(dp,-1,sizeof(dp));

    if(vec[0] >= 0){
        ll a = 1 + calc(1, vec[0]);
        ll b = calc(1, 0);
        dp[0] = max(a, b);
    }
    else dp[0] = calc(1, 0);
    cout << dp[0] << endl;
}
int main() {
    FAST_FURIER;
    int tt=1;
    // cin >> tt;
    while(tt--){
        solve();
    }
}