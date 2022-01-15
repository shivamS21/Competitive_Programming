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
vector<int> adj[100000];
vector<int> parent(1e5, 0);
int found = 0;
void printCycle(int node, int p){
    // cout << "print node nad parent " << node << " " << p << endl;
    vector<int> road;
    road.pb(node);
    while(p != node){
        road.pb(p);
        p = parent[p];
    }
    road.pb(p);
    cout << road.size() << endl;
    print(road);

}
void dfs(int node, int par){
    if(parent[par] == node) return;
    // cout <<node << " " << par << endl;
    parent[node] = par;
    for(int ele: adj[node]){
        if(ele == par) continue;
        // cout << "YES " << ele << endl;
        if(!parent[ele]){
            dfs(ele, node);
        }
        else if(parent[node] != ele){
            found = 1;
            printCycle(ele, node);
        }
        if(found) return;
    }
}
void solve(){
    ll m,n,k;
    cin >> n >> m;
    // adj.resize(n+1);
    for(int i = 0; i < m; i++){
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 1; i <= n; i++){
        if(!parent[i])
        dfs(i, i);
        if(found){
            return;
        }
    }
    cout << "IMPOSSIBLE";
}
int main() {
    FAST_FURIER;
    int tt=1;
    // cin >> tt;
    while(tt--){
        solve();
    }
}
 