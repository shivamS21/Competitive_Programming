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
    //this is basically called the path compression which helps to 
    //bring down the query complexities down to constant (logn in some cases which we are going to discuss now)
}
void union_sets(int a, int b, int &comp, int &largesize){
    int u = find_set(a);
    int v = find_set(b);
    if(u != v){
        //means parents are not equal
        if(size[u] < size[v])
        swap(u, v);
        parent[v] = u;
        size[u] += size[v];
        largesize = max(largesize, size[u]);
        --comp;
    }
    
}
void solve(){
    ll m,n,k;
    cin >> n >> m;
    int comp = n, largesize = 1;
    for(int i = 1; i <= n; i++){
        parent[i] = i;
        size[i] = 1;
    }
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        union_sets(a, b, comp, largesize);
        cout << comp << " " << largesize << endl;
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
 