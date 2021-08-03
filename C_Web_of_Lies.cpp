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
    cin >> n >> m;
    vector<set<int> > adj(n+10);
    rep(i,0,m){
        int a, b;
        cin >> a >> b;
        adj[a].insert(b);
        adj[b].insert(a);
    }
    set<int> s;
    // cout << "suze " << s.size() << endl;
    int q; cin >> q;
    rep(i,1,n+1){
        if(adj[i].upper_bound(i) == adj[i].end()){
            s.insert(i);
        }
    }
    while(q--){
        int a; cin >> a;
        if(a==1){
            int u, v; cin >> u >> v;
            adj[u].insert(v);
            adj[v].insert(u);
            if(adj[u].upper_bound(u) != adj[u].end() and s.find(u) != s.end())
            s.erase(u);
            if(adj[v].upper_bound(v) != adj[v].end() and s.find(v) != s.end())
            s.erase(v);
        } else if(a == 2){
            int u,  v; cin >> u >> v;
            adj[u].erase(v);
            adj[v].erase(u);
            if(adj[u].upper_bound(u) == adj[u].end() ) s.insert(u);
            if(adj[v].upper_bound(v) == adj[v].end())  s.insert(v);
        } else{
            cout << s.size() << endl;
        }
    }
    
}
int main() {
    FAST_FURIER;
    int tt=1;
    // cin >> tt;
    while(tt--){
        solve();
    }
}
 