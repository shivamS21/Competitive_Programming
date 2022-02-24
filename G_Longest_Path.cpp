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
vector<int> dp;
int dfs(int node, vector<int> adj[]){
    if(dp[node]) return dp[node];
    int &res = dp[node];
    for(int x: adj[node]){
        res = max(res, 1 + dfs(x, adj));
    }
    return res;
}
void solve(){
    ll m,n,k;
    cin >> n >> m;
    vector<int> adj[n+1];
    dp.resize(n+1);
    for(int i = 0; i < n+1; i++) dp[i] = 0;
    for(int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    vector<int> visited(n+1, 0);
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(!dp[i])
        ans = max(ans, dfs(i, adj));
    }
    // for(int i = 0; i <= n; i++) cout << i << " " << dp[i] << endl;
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
 