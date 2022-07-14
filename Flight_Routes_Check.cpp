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
void dfs(int node, vector<int> adj[], vector<int> &visited){
    visited[node] = 1;
    for(int ele: adj[node]){
        if(!visited[ele])
        dfs(ele, adj, visited);
    }
}
void solve(){
    ll m,n,k;
    cin >> n >> m;
    vector<int> adj1[n+1], adj2[n+1];
    for(int i = 0; i< m; i++){
        int a, b; cin >> a >> b;
        adj1[a].push_back(b);
        adj2[b].push_back(a);
    }
    vector<int> visited1(n+1, 0);
    dfs(1, adj1, visited1);
    vector<int> visited2(n+1, 0);
    dfs(1, adj2, visited2);
    int f = -1;
    int a = 1;
    for(int i = 1; i <= n; i++){
        if(!visited1[i]){
            f = i;
            break;
        }
        if(!visited2[i]){
            a = i;
            f = 1;
            break;
        }
    }
    if(f==-1) cout << "YES";
    else {
        cout << "NO\n" << a << " " << f << endl;
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
 