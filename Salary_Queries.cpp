//...START BY DOING WHAT IS NECESSARY, THEN WHAT IS POSSIBLE AND SUDDENLY YOU ARE DOING THE IMPOSSIBLE... 
#include <bits/stdc++.h>
using namespace std;typedef long long ll;
#define FAST_FURIER ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define pb push_back
#define mk make_pair
#define sorta(v)        sort(v.begin(), v.end())
#define sortd(v)        sort(v.begin(), v.end(), comp)
#define rep(i,a,N)      for(int i=a;i<N;i++)
#define rrep(i,a,N)     for(ll i=a;i>N;i--)
#define print(v)        for(ll ite=0;ite<v.size();ite++){cout<<v[ite]<<' ';}cout<<endl;
#define M 1000000007
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using cust_set = tree<T, null_type,less<T>, rb_tree_tag, tree_order_statistics_node_update>;
cust_set<array<int,2>> f;
bool comp(ll x,ll y){
    return x > y;
}
 
/*...............code starts here................*/
// C is first won in M
 
void solve(){
    ll m,n,k;
    cin >> n >> k;
    vector<int> vec(n+1);
    multiset<int> s;
    rep(i,1,n+1){
        cin >> vec[i];
        f.insert({vec[i],i});
    }
    rep(i,0,k){
        char c; cin >> c;
        if(c=='?'){
            int a,b; cin >> a >> b;
            cout << f.order_of_key({b+1,1}) - f.order_of_key({a,1}) << endl;
        }
        else{
            int k,x; cin >> k >> x;
            f.erase({vec[k], k});
            vec[k] = x;
            f.insert({vec[k], k});
        }
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