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
 void dfs(int n, vector<int> adj[], int val[], int &path, int len, int node, unordered_map<int,int>&mp, int valMax, int mx, vector<int> &visited){
    mp[val[node]]++;
    //mx=maximum value in map
    visited[node] = 1;
    if(mp[val[node]] > mx){
        valMax = val[node];
        mx = mp[val[node]];
    }
    ++len;
    if(mx >= len/2+len%2) ++path;
    for(int ele: adj[node]){
        if(!visited[ele])
        dfs(n, adj, val, path, len, ele, mp, valMax, mx, visited);
    }
    mp[val[node]]--;
 }
void solve(){
    ll m,n,k;
    cin >> n;
    int val[n+1];
    for(int i = 1; i < n+1; i++){
        cin >> val[i];
    }
    vector<int> adj[n+1];
    vector<int> visited(n+1, 0);
    for(int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    int path = 0, len = 0 ;
    unordered_map<int,int> mp;
    dfs(n, adj, val, path, len, 1, mp, 0, 0, visited);
    cout << path << endl;
}
int main() {
    FAST_FURIER;
    int tt=1;
    cin >> tt;
    while(tt--){
        solve();
    }
}
 