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
void solve(){
    ll n, m;
    cin >> n >> m;
    vector<vector<int>>edges;
    for(int i = 0; i < m; i++){
        ll u, v, w;
        vector<int> vec(3);
        cin >> vec[0] >> vec[1] >> vec[2];
        edges.push_back(vec);
    }
    vector<ll>distance(n+1, 1e17), parent(n+1, -1);
    int x = -1;
    for(int i = 1; i <= n; i++){
        //relaxing n-1 times
        for(int j = 0; j < m; j++){
            if(distance[edges[j][0]] != 1e17 and distance[edges[j][0]]+edges[j][2] < distance[edges[j][1]])
            {
                distance[edges[j][1]] = distance[edges[j][0]]+edges[j][2];
                x = edges[j][1];
                parent[edges[j][1]] = edges[j][0];
            }
        }
    }
    if(x == -1){
        cout << "NO";
    } else{
        cout <<"YES"<<endl;
        vector<int> cycle;
        for(int i = 1; i <= n; i++)
        x = parent[x];

        for(int v = x; ; v = parent[v]){
            cycle.push_back(v);
            if(v == x and cycle.size()>1)
            break;
        }
        reverse(cycle.begin(), cycle.end());
        for(int ele: cycle) cout << ele << " ";
    }
}
int main() {
    FAST_FURIER;
    int tt=1;
    // cin >> tt;
    while(tt--) solve();
}
