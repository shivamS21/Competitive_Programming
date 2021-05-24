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
ll dp[100005][2];
vector<pair<ll,ll> > v(100005);
ll calc(ll p, ll i, ll val, vector<vector<ll> > adj){
    cout << p << " " << i << endl;
    if(adj[p].size()==0)
    return 0;
    ll &res = dp[p][i];
    if(res != -1)
    return res;
    ll ans = 0;
    for(ll node: adj[p]){
        ll a = abs(val - v[node].first) + calc(node, 0, v[node].first, adj);
        ll b = abs(val - v[node].second) + calc(node, 1, v[node].second, adj);
        ans += max(a, b);
    }
    res = ans;
    return res;
}
void solve(){
    ll m,n,k;
    cin >> n;
    vector<pair<ll,ll> > v(n+1);
    rep(i,1,n+1){
        cin >> v[i].first >> v[i].second;
    }
    vector<vector<ll> > adj(n+1);
    rep(i,0,n-1){
        ll a, b; cin >> a >> b;
        adj[a].pb(b);
    }
    mem(dp,-1);
    dp[1][0] = calc(1, 0, v[1].first, adj);
    dp[1][1] = calc(1, 1, v[1].second, adj);
    cout<<max(dp[1][0], dp[1][1])<<endl;

}
int main() {
    FAST_FURIER;
    int tt=1;
    cin >> tt;
    while(tt--){
        solve();
    
    }
}
 
 
 
 
// g++ -std=c++17