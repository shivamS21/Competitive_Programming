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
vector<vector<ll> > v(100005, vector<ll>(2,0));
ll dp[100005][2];
ll calc(ll x, ll index, ll p, vector<ll> adj[]){
    ll &res = dp[x][index];
    if(res != -1)
    return res;
    ll temp = 0;
    for(ll node: adj[x]){
        if(node != p){
            ll a = abs(v[x][index] - v[node][0]) + calc(node, 0, x, adj);
            ll b = abs(v[x][index] - v[node][1]) + calc(node, 1, x, adj);
            temp += max(a, b);
        }
    }
    res = temp;
    return res;
}
void solve(){
    ll m,n,k;
    cin >> n;
    vector<ll> adj[n+1];
    rep(i,1,n+1){
        cin >> v[i][0] >> v[i][1];
        dp[i][0] = -1;
        dp[i][1] = -1;
    }
    rep(i,0,n-1){
        ll a, b; cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    ll a = calc(1, 0, -1, adj);
    ll b = calc(1, 1, -1, adj);
    cout<< max(a, b) << endl;
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