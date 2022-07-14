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
int size[100005];
int parent[100005];
int find_set(int v){
    if(v == parent[v]) return v;
    return parent[v] = find_set(parent[v]);
}
void solve(){
    ll m,n,k;
    cin >> n >> m;
    vector<vector<ll> > v(m, vector<ll>(3, 0));
    for(int i = 1; i < n+1; i++){
        parent[i] = i;
        size[i] = 1;
    }
    for(int i = 0; i < m; i++){
        cin >> v[i][1] >> v[i][2] >> v[i][0];
    }
    sort(v.begin(), v.end());
    ll comp = n, totalCost = 0;
    for(int i = 0; i < m; i++){
        int a = v[i][1], b = v[i][2];
        int cost = v[i][0];
        a = find_set(a);
        b = find_set(b);
        if(a != b){
            //measns parents are different
            comp--;
            if(size[a] < size[b])
            swap(a, b);
            parent[b] = a;
            size[a] += size[b];
            totalCost += cost;
        }
    } 
    if(comp!=1) cout << "IMPOSSIBLE";
    else
    cout << totalCost;
}
int main() {
    FAST_FURIER;
    int tt=1;
    // cin >> tt;
    while(tt--){
        solve();
    }
}
 