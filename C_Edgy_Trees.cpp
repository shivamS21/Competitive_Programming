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

vector<int> adj[100002];
vector<int> visited(100004,-1);
int n, k;
ll power(ll no,ll p, ll mod)
{
    if(p == 1)
    return no;
    if(p == 0)
    return 1;
    ll q = power(no,p/2,mod);
    q = (q*q)%M;
    if(p % 2 != 0)
    q = (q*no)%M;
    return q;
}
ll bfs(int node){
    queue<int> q;
    q.push(node);
    ll count = 0;
    while(!q.empty()){
        int ele = q.front();
        q.pop();
        visited[ele] = 1;
        count += 1;
        for(auto x: adj[ele]){
            if(visited[x] == -1)
            q.push(x);
        }
    }
    return power(count, k, M) % M;
}
void solve(){
    cin >> n >> k;
    rep(i,0,n-1){
        int u, v, x; 
        cin >> u >> v >> x;
        if(x ==1) continue;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    ll ans = 0;
    rep(i,1,n+1){
        //run bfs for each vertices
        if(visited[i] == -1)
        ans = (ans + bfs(i))%M;
    }
    cout << (power(n, k, M)%M - ans+ M)%M << endl;
}
int main() {
    FAST_FURIER;
    int tt=1;
    // cin >> tt;
    while(tt--){
        solve();
    }
}
 