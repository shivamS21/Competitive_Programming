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
    for(int i = 1; i <= m; i++){
        int a, b; cin >> a>> b; 
        adj[a].push_back(b);
    }
    vector<vector<int>>visited(n+1);
    //vector[i]: maximum cities path from 1 to i
    //I will use bfs 
    queue<int> q;
    q.push(1);
    visited[1].push_back(1);
    while(!q.empty()){
        int city = q.front();
        q.pop();
        for(int flight: adj[city]){
            if(visited[flight].size() < visited[city].size()+1){
                q.push(flight);
                visited[flight] = visited[city];
                visited[flight].push_back(flight);
            }
        }
    }
    if(visited[n].size()==0){
        cout<<"IMPOSSIBLE\n";
        return;
    }
    cout << visited[n].size() << "\n";
    for(int ele: visited[n]) cout << ele << " ";

    
}
int main() {
    FAST_FURIER;
    int tt=1;
    // cin >> tt;
    while(tt--){
        solve();
    }
}
 