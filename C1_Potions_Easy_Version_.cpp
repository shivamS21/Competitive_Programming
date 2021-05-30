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
ll dp[2001][2001]; 
vector<ll> vec;
ll n;
ll calc(ll i, ll count, ll val){
    if(i==n) return 0;
    ll &res = dp[i]
}
void solve(){
    cin >> n;
    vec.resize(n);
    rep(i,1,n+1) cin >> vec[i];
    // dp[i][j] gives the no of ways where one can select j values in the [1..i] segment.
    // if vec[i] > 0 then I can simple add it. 
    // else I can choose it if the current value + vec[i] >= 0 or not choose it
    // else I cant choose this.
    if(vec[0]>-1)
    dp[1][1] = calc(1,0,0);
    else
    dp[1][0] = calc(1,0,0)
}
int main() {
    FAST_FURIER;
    int tt=1;
    // cin >> tt;
    memset(dp,-1,sizeof(dp));
    while(tt--){
        solve();
    }
}
 