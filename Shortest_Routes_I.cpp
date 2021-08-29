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
vector<pair<ll, ll> > adj[100005];
vector<int> visited(100005, 0);
vector<ll> dist(100005, 1e18);
int n, m;
void djikstra(){
    set<pair<ll, ll> > s;
    s.insert({0, 1});
    dist[1] = 0;
    while(!s.empty()){
        ll u = (*s.begin()).second;
        s.erase(s.begin());
        visited[u] = 1;
        for(pair<ll,ll> v: adj[u]){
            if(!visited[v.first] && dist[u]+v.second < dist[v.first]){
                s.erase({dist[v.first], v.first});
                dist[v.first] = dist[u]+v.second;
                s.insert({dist[v.first], v.first});
            }
        }
    }
    rep(i,1,n+1)cout << dist[i] << " "; cout << endl;
}
void solve(){
    cin >> n >> m;
    rep(i,0,m){
        ll u, v, w; cin >> u >> v >> w;
        adj[u].pb({v, w});
    }
    djikstra();
    
}
int main() {
    FAST_FURIER;
    int tt=1;
    // cin >> tt;
    while(tt--){
        solve();
    }
}
 