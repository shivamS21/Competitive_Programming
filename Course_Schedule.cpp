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
    vector<int> adj[n+1];
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
    }
    vector<int> indegree(n+1, 0);
    for(int i = 1; i <= n; i++){
        for(int ele: adj[i]){
            indegree[ele]++;
        }
    }
    queue<int> q;
    vector<int> topo;
    for(int i = 1; i<n+1; i++){
        if(!indegree[i]) q.push(i);
    }
    int nodes = 0;
    while(!q.empty()){
        int ele = q.front();
        q.pop();
        topo.push_back(ele);
        for(int adjNode: adj[ele]){
            indegree[adjNode]--;
            if(indegree[adjNode]==0)
            q.push(adjNode);
        }
        ++nodes;
    }
    if(nodes==n){
        for(int ele: topo) cout << ele << " ";
    } else cout << "IMPOSSIBLE";
    
}
int main() {
    FAST_FURIER;
    int tt=1;
    // cin >> tt;
    while(tt--){
        solve();
    }
}
 