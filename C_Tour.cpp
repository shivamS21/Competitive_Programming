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
int bfs(int node, vector<int> adj[], int n){
    int ans = 1;
    vector<int> visited(n+1,0);
    queue<int> q;
    q.push(node);
    // cout << node << ": " << node << endl;
    while(!q.empty()){
        int ele = q.front();
        q.pop();
        for(int v: adj[ele]){
            if(visited[v]) continue;
            if(v != node)
            ans += 1;
            q.push(v);
            visited[v] = 1;
            // cout << node << ": " << v << endl;
        }
    }
    return ans;
}
void solve(){
    ll m,n,k;
    cin >> n >> m;
    vector<int> adj[n+1];
    rep(i,0,m){
        int a,b; cin >> a >> b;
        adj[a].pb(b);
    }
    int ans = 0;
    rep(i,1,n+1)
    ans += bfs(i, adj, n);
    cout << ans;
}
int main() {
    FAST_FURIER;
    int tt=1;
    // cin >> tt;
    while(tt--){
        solve();
    }
}
 