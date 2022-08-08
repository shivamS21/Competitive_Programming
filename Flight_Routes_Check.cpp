#include <bits/stdc++.h>
using namespace std;typedef long long ll;
#define FAST_FURIER ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define sorta(v)        sort(v.begin(), v.end())
#define sortd(v)        sort(v.begin(), v.end(), comp)
#define M 1000000007
#define ll long long
bool comp(ll x, ll y){
    return x > y; }
/*...............code starts here................*/
void dfs(int node, vector<int>&visited, vector<int> adj[]){
    visited[node] = true;
    for(int ele: adj[node]){
        if(!visited[ele])
        dfs(ele, visited, adj);
    }
}
void solve(){
    ll n, m; cin >> n >> m;
    vector<int> adj[n+1], reverseadj[n+1];
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        reverseadj[b].push_back(a);
    }
    vector<int> visited(n+1, 0);
    dfs(1, visited, adj);
    vector<int> visitedreverse(n+1, 0);
    dfs(1, visitedreverse, reverseadj);
    int flag = 0, from, to;
    for(int i = 1; i <= n; i++){
        if(visited[i] and visitedreverse[i]) continue;
        else if(!visited[i]){
            flag = 1;
            from = 1;
            to = i;
        } else{
            flag = 1;
            from = i;
            to = 1;
        }
    }
    if(flag){
        cout << "NO" << endl << from << " " << to << endl;
    } else cout << "YES";
}
int main() {
    FAST_FURIER;
    int tt=1;
    // cin >> tt;
    while(tt--) solve();
}
