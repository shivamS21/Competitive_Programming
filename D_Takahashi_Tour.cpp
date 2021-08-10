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
int find_node(vector<set<int> > &vec, int node, vector<int> &visited){
    while(vec[node].size() and visited[*vec[node].begin()])
    vec[node].erase(vec[node].begin());
    if(!vec[node].size()){
        return -1;
    }
    int temp = *vec[node].begin();
    vec[node].erase(vec[node].begin());
    visited[temp] = 1;
    return temp;
} 
void solve(){
    ll m,n,k;
    cin >> n;
    vector<set<int> > vec(n+4);
    rep(i,0,n-1){
        int a, b; cin >> a >> b;
        vec[a].insert(b);
        vec[b].insert(a);
    }
    int node = 1;
    vector<int> path, visited(n+4, 0);
    vector<int> ans; ans.pb(1);
    visited[1] = 1;
    while(true){
        if(node == 1 and !vec[node].size()) break;
        int temp = find_node(vec, node, visited);
        if(temp == -1){
            node = path.back();
            path.erase(--path.end());
        } else{
            path.pb(node);
            node = temp;
        }
        ans.pb(node);
    }
    print(ans);
}
int main() {
    FAST_FURIER;
    int tt=1;
    // cin >> tt;
    while(tt--){
        solve();
    }
}
 