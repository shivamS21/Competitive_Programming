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

ll count(vector<int> adj[], int n){
	ll ans = 0;
    vector<int> visited(n+10,0);
    vector<int> dist(n+10, INT_MAX), path(n+10, 0);
	path[1] = 1;
	queue<int> q;
	q.push(1);
	visited[1] = 1;
	while(!q.empty()){
		int x = q.front();
		q.pop();
		for(int ele: adj[x]){
			if(visited[ele] == 0){
				visited[ele] = 1;
				q.push(ele);
			}

			if(dist[ele] > dist[x]+1){
				dist[ele] = dist[x]+1;
				path[ele] = path[x];
			} else if(dist[ele] == dist[x]+1){
				path[ele] = (path[ele] + path[x])%M;
			}
		}
	}
	return path[n];
}
void solve(){
    ll m,n,k;
    cin >> n >> m;
    vector<int> adj[n+10];
    rep(i,0,m){
        int a, b; cin >> a >> b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    cout << count(adj, n)%M << endl;
	
}
int main() {
    FAST_FURIER;
    int tt=1;
    // cin >> tt;
    while(tt--){
        solve();
    }
}
 